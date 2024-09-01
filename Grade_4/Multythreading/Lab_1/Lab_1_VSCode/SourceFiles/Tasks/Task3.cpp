#include "Task3.hpp"

#include <QDebug>
#include <QMetaObject>
#include <QtConcurrent/QtConcurrent>
#include <QThread>

#include <thread>

namespace Tasks {

void Task3::run() {
    qDebug() << __PRETTY_FUNCTION__ << "called";

    QThread increment_th, decrement_th;
    Counter counter;
    qint32 loop_count{1000};

    QObject::connect(&increment_th, &QThread::started, [&counter, loop_count, &increment_th](){ 
        for (qint32 i{0}; i < loop_count; ++i) {
            counter.increment(); 
            increment_th.quit();
        }
    });
    QObject::connect(&decrement_th, &QThread::started, [&counter, loop_count, &decrement_th](){ 
        for (qint32 i{0}; i < loop_count; ++i) {
            counter.decrement(); 
            decrement_th.quit(); 
        }
    });

    increment_th.start();
    decrement_th.start();

    increment_th.wait();
    decrement_th.wait();

    qInfo() << "Counter value = " << counter.get_counter();
}

Counter::Counter()
: _counter{0} {

}

void Counter::increment() {
    ++_counter;
}

void Counter::decrement() {
    --_counter;
}

qint32 Counter::get_counter() const noexcept {
    return _counter.loadAcquire();
}

} // Tasks
