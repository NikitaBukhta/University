#include "ExperementalObject.hpp"
#include "NewThread.hpp"
#include "WorkerRunnable.hpp"

#include <QCoreApplication>
#include <QPointer>
#include <QThreadPool>

#include <iostream>
#include <vector>

void task_1() {
  NewThread newThread;
  newThread.start();
  newThread.wait();

  std::cout << "task 1 finished" << std::endl;
}

void task_2() {
  for (qint32 i{0}; i < 3; ++i) {
    WorkerRunnable *worker = new WorkerRunnable;
    worker->setAutoDelete(true); // auto delete pointer when work is finished;
    QThreadPool::globalInstance()->start(worker);
  }

  QThreadPool::globalInstance()->waitForDone();
  std::cout << "task 2 finished" << std::endl;
}

void task_3() {
  ExperementalObject *worker = new ExperementalObject;
  worker->setAutoDelete(false);

  for (qint32 i{0}; i < 3; ++i) {
    QThreadPool::globalInstance()->start(worker);
  }

  QThreadPool::globalInstance()->waitForDone();
  delete worker;

  std::cout << "task 3 finished" << std::endl;
}

int main(int argc, char *argv[]) {
  QCoreApplication app(argc, argv);

  task_1();
  task_2();
  task_3();

  return app.exec();
}