#include "Numbers.hpp"

#include <iostream>

namespace lab_2 {
namespace task_3 {

bool Numbers::setValues(double a, double b, double c) noexcept {
    m_a = a;
    m_b = b;
    m_c = c;
    return true;
}

bool Numbers::print(void) const {
    std::cout << "<" << m_a << ", " << m_b << ", " << m_c << ">\n";
    return true;
}

}   // !task_3;
}   // !lab_2;