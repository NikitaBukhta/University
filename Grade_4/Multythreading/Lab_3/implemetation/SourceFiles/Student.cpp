#include "Student.hpp"

Student::Student(common::FullName fullName, float avarageGrade)
    : _fullName{fullName}, _avarageGrade{avarageGrade} {}

bool Student::operator==(const Student &other) const {
  return this->_avarageGrade == other._avarageGrade &&
         this->_fullName == other._fullName;
}

bool Student::operator!=(const Student &other) const {
  return !operator==(other);
}

bool Student::operator>(const Student &other) const {
  return this->_fullName > other._fullName ||
         (this->_fullName == other._fullName &&
          this->_avarageGrade > other._avarageGrade);
}

bool Student::operator<(const Student &other) const {
  return this->_fullName < other._fullName ||
         (this->_fullName == other._fullName &&
          this->_avarageGrade < other._avarageGrade);
}

common::FullName Student::fullName() const { return _fullName; }

void Student::setFullName(common::FullName &val) { _fullName = val; }

void Student::setFullName(common::FullName &&val) {
  _fullName = std::move(val);
}

float Student::avarageGrade() const noexcept { return _avarageGrade; }

void Student::setAvarageGrade(float val) noexcept { _avarageGrade = val; }