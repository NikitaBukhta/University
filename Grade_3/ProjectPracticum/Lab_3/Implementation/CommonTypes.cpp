#include "CommonTypes.hpp"

namespace lab_3 {
namespace common_types {

std::ostream& operator<<(std::ostream &out, const FullName &value) {
    out << value.second_name << ' ' << value.first_name;
    if (value.middle_name.size()) {
        out << ' ' << value.middle_name;
    }

    return out;
}

std::string to_string(POSITION val) {
    switch(val) {
    case POSITION::COMMON_SPECIALIST:
        return "COMMON_SPECIALIST";
    case POSITION::FIRST_CATEGORY_SPECIALST:
        return "FIRST_CATEGORY_SPECIALST";
    case POSITION::SECOND_CATEGORY_SPECIALST:
        return "SECOND_CATEGORY_SPECIALST";
    case POSITION::HIGH_CATEGORY_SPECIALIST:
        return "HIGH_CATEGORY_SPECIALIST";
    case POSITION::BRANCH_MANAGER:
        return "BRANCH_MANAGER";
    case POSITION::DIRECTOR:
        return "DIRECTOR";
    }

    return {};
}

}   // !common_types;
}   // !lab_3;