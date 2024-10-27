#ifndef __LAB_3_MULTYTHREADING_STUDENT_HPP__
#define __LAB_3_MULTYTHREADING_STUDENT_HPP__

#include "common.hpp"

class Student {
public:
  Student() = default;
  Student(common::FullName fullName, float avarageGrade);

  bool operator==(const Student &other) const;
  bool operator!=(const Student &other) const;
  bool operator>(const Student &other) const;
  bool operator<(const Student &other) const;

  common::FullName fullName() const;
  void setFullName(common::FullName &val);
  void setFullName(common::FullName &&val);

  float avarageGrade() const noexcept;
  void setAvarageGrade(float val) noexcept;

private:
  common::FullName _fullName;
  float _avarageGrade;
};

#endif // __LAB_3_MULTYTHREADING_STUDENT_HPP__;