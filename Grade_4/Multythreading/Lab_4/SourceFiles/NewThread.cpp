#include "NewThread.hpp"

#include <iostream>

void NewThread::run() {
  for (qint32 i{0}; i < 100; ++i) {
    std::cout << "|";
  }
  std::cout << std::endl;
}