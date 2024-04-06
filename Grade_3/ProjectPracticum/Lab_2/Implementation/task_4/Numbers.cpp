#include "Numbers.hpp"

#include <iostream>

namespace lab_2 {
namespace task_4 {

bool Numbers::isEqual(const Numbers &other) const {
    return this->m_a == other.m_a && this->m_b == other.m_b
        && this->m_c == other.m_c;
}

bool Numbers::setValues(double a, double b, double c) noexcept{
    m_a = a;
    m_b = b;
    m_c = c;
    return true;
}

bool Numbers::print(void) const {
    std::cout << "<" << m_a << ", " << m_b << ", " << m_c << ">\n";
    return true;
}

}   // !task_4;
}   // !lab_2;