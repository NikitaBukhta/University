#ifndef __LAB3_TASKS_TASK1_HPP__
#define __LAB3_TASKS_TASK1_HPP__

#include <QRunnable>
#include <QAtomicInt>

namespace Tasks {

class Task3 : public QRunnable {
public:
    void run() override;
};

class Counter {
public:
    Counter();
    void increment();
    void decrement();

    qint32 get_counter() const noexcept;

private:
    QAtomicInt _counter;
};

} // Tasks

#endif // __LAB3_TASKS_TASK1_HPP__