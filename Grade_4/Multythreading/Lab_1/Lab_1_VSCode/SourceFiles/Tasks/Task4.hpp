#ifndef __LAB4_TASKS_TASK1_HPP__
#define __LAB4_TASKS_TASK1_HPP__

#include <QRunnable>
#include <QVector>

namespace Tasks {

class Task4 : public QRunnable {
public:
    void run() override;
};

class Result {
public:
    QVector<QVector<int>> _matrix;

    Result(int rows, int cols);
    ~Result();

    void set_value(int row, int col, int value);
    int get_value(int row, int col) const;
};

} // Tasks

#endif // __LAB4_TASKS_TASK1_HPP__