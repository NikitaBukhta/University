#ifndef __LAB2_TASKS_TASK2_HPP__
#define __LAB2_TASKS_TASK2_HPP__

#include <QRunnable>
#include <QObject>
#include <QWaitCondition>
#include <QMutex>

namespace Tasks {

class Task2 : public QRunnable {
private:
    enum class TurnEnumeration : quint8 {
        Dash = 0,
        Pipe = 1
    };

public:
    void run() override;

    virtual ~Task2() = default;

private:

};

class ConsoleSyncWriter : public QObject {
public:
    ConsoleSyncWriter(const std::wstring& str, const qint32 turn_number);

public:
    static qint32 get_terminal_width();

public slots:
    void write(QAtomicInt& current_turn, qint32 next_turn);
    void write_repeatly(QAtomicInt& current_turn, qint32 next_turn, qint32 repeat_count);

private:
    std::wstring _str;
    const qint32 _turn_number;

    static QWaitCondition _waiter;
    static QMutex _write_mutex;
};

} // namespace Tasks

#endif // __LAB2_TASKS_TASK2_HPP__
