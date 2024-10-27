#include "ExperementalObject.hpp"

#include <iostream>

ExperementalObject::ExperementalObject() : _character{'a'} {}

void ExperementalObject::run() {
  for (qint32 i{0}; i < 100; ++i) {
    std::cout << _character.loadAcquire();
  }
  ++_character;

  std::cout << std::endl;
}