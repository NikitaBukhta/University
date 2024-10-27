#ifndef __LAB_4_MULTYHTREADING_WORKERRUNNABLE_HPP__
#define __LAB_4_MULTYHTREADING_WORKERRUNNABLE_HPP__

#include <QRunnable>
#include <QThread>

class WorkerRunnable : public QRunnable {
public:
  ~WorkerRunnable();

  void run() override;
};

#endif // __LAB_4_MULTYHTREADING_WORKERRUNNABLE_HPP__;