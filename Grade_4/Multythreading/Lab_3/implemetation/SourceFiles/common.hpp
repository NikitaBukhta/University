#ifndef __LAB_3_MULTYTHREADING_COMMON_HPP__
#define __LAB_3_MULTYTHREADING_COMMON_HPP__

#include <string>

namespace common {

struct FullName {
  std::string name;
  std::string surname;
  std::string middleName;

public:
  bool operator==(const FullName &other) const;
  bool operator!=(const FullName &other) const;
  bool operator>(const FullName &other) const;
  bool operator<(const FullName &other) const;
};

} // namespace common

#endif // __LAB_3_MULTYTHREADING_COMMON_HPP__;