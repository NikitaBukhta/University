#ifndef __LAB_4_MULTYHTREADING_NEWTHREAD_HPP__
#define __LAB_4_MULTYHTREADING_NEWTHREAD_HPP__

#include <QThread>

class NewThread : public QThread {
public:
  void run() override;
};

#endif // __LAB_4_MULTYHTREADING_NEWTHREAD_HPP__;