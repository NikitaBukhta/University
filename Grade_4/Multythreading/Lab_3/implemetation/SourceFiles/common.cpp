#include "common.hpp"

namespace common {

bool FullName::operator==(const FullName &other) const {
  return this->name == other.name && this->surname == other.surname &&
         this->middleName == other.middleName;
}

bool FullName::operator!=(const FullName &other) const {
  return !operator==(other);
}

bool FullName::operator>(const FullName &other) const {
  return this->surname > other.surname && this->name > other.name &&
         this->middleName > other.middleName;
}

bool FullName::operator<(const FullName &other) const {
  return this->surname < other.surname && this->name < other.name &&
         this->middleName < other.middleName;
}

} // namespace common