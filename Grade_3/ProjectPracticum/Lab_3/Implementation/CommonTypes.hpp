/************************************
 * Laboratory work #3;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB3_COMMONTYPES_HPP
#define BUKHTAMYKYTA_LAB3_COMMONTYPES_HPP

#include <string>
#include <ostream>

namespace lab_3 {
namespace common_types {

struct FullName {
    std::string first_name;
    std::string second_name;
    std::string middle_name;

    friend std::ostream& operator<<(std::ostream &out, const FullName &value);
};

enum class POSITION {
    COMMON_SPECIALIST,
    FIRST_CATEGORY_SPECIALST,
    SECOND_CATEGORY_SPECIALST,
    HIGH_CATEGORY_SPECIALIST,
    BRANCH_MANAGER,
    DIRECTOR,
    SIZE
};

std::string to_string(POSITION val);

}   // !common_types;
}   // !lab_3;

#endif  // !BUKHTAMYKYTA_LAB3_COMMONTYPES_HPP;