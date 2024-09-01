#include "Task2.hpp"

#include <QDebug>
#include <QThread>

#include <iostream>
#include <string>

#include <sys/ioctl.h>

namespace Tasks {

QWaitCondition ConsoleSyncWriter::_waiter;
QMutex ConsoleSyncWriter::_write_mutex;

void Task2::run() {
    qDebug() << __PRETTY_FUNCTION__ << "called";

    QThread dash_th, pipe_th;
    ConsoleSyncWriter dash_writer{L"-", static_cast<qint32>(TurnEnumeration::Dash)};
    ConsoleSyncWriter pipe_writer{L"|", static_cast<qint32>(TurnEnumeration::Pipe)};
    qint32 rows_count = 10;
    qint32 colums_count = ConsoleSyncWriter::get_terminal_width();
    QAtomicInt current_turn = static_cast<qint32>(TurnEnumeration::Dash);

    dash_writer.moveToThread(&dash_th);
    pipe_writer.moveToThread(&pipe_th);

    QObject::connect(&dash_th, &QThread::started, [&](){
        dash_writer.write_repeatly(current_turn, static_cast<qint32>(TurnEnumeration::Pipe), rows_count * colums_count / 2);
        dash_th.quit(); // in case if quit isn't used, the main thread is locked on the wait() method called (str 46);
    });
    QObject::connect(&pipe_th, &QThread::started, [&](){
        pipe_writer.write_repeatly(current_turn, static_cast<qint32>(TurnEnumeration::Dash), rows_count * colums_count / 2);
        pipe_th.quit();
    });

    dash_th.start();
    pipe_th.start();
    
    // There is a framework bug?
    dash_th.wait();
    pipe_th.wait();
}

ConsoleSyncWriter::ConsoleSyncWriter(const std::wstring& str, const qint32 turn_number) 
: _str{str}
, _turn_number{turn_number} {

}

qint32 ConsoleSyncWriter::get_terminal_width() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

void ConsoleSyncWriter::write(QAtomicInt& current_turn, qint32 next_turn) {
    QMutexLocker locker(&_write_mutex);

    while (current_turn.loadAcquire() != _turn_number) {
        _waiter.wait(&_write_mutex);
    }

    std::wcout << _str << std::flush;

    current_turn.storeRelease(next_turn);
    _waiter.wakeOne();
}


void ConsoleSyncWriter::write_repeatly(QAtomicInt& current_turn, qint32 next_turn, qint32 repeat_count) {
    qDebug() << "repeat count = " << repeat_count;
    for (qint32 i{0}; i < repeat_count; ++i) {
        write(current_turn, next_turn);
    }

    qDebug() << __PRETTY_FUNCTION__ << "finished";
}

} // Tasks
