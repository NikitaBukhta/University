#ifndef __LAB1_TASKS_TASK1_HPP__
#define __LAB1_TASKS_TASK1_HPP__

#include <QRunnable>

namespace Tasks {

class Task1 : public QRunnable {
public:
    void run() override;
};

} // Tasks

#endif // __LAB1_TASKS_TASK1_HPP__