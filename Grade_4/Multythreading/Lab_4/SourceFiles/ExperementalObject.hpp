#ifndef __LAB_4_MULTYHTREADING_EXPEREMENTALOBJECT_HPP__
#define __LAB_4_MULTYHTREADING_EXPEREMENTALOBJECT_HPP__

#include <QAtomicInteger>
#include <QRunnable>

class ExperementalObject : public QRunnable {
public:
  ExperementalObject();
  void run() override;

private:
  QAtomicInteger<char> _character;
};

#endif // __LAB_4_MULTYHTREADING_EXPEREMENTALOBJECT_HPP__;