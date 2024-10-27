#include "WorkerRunnable.hpp"

#include <iostream>

WorkerRunnable::~WorkerRunnable() {
  std::cout << "Delete object " << this << std::endl;
}

void WorkerRunnable::run() {
  for (qint32 i{0}; i <= 100; i += 10) {
    std::cout << i << " ";
    QThread::msleep(100);
  }

  std::cout << std::endl;
}