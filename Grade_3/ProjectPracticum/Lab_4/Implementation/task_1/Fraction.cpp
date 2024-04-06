#include "Fraction.hpp"

#include <iostream>

namespace lab_4 {

Fraction::Fraction(int32_t numerator, int32_t pronount)
    : m_numerator{numerator}, m_pronount(pronount)
{

}

Fraction Fraction::operator* (const Fraction &other) const noexcept{
    return Fraction{
        this->m_numerator * other.m_numerator,
        this->m_pronount * other.m_pronount
    };
}

Fraction Fraction::operator* (int32_t numerator) const noexcept {
    return Fraction{
        this->m_numerator * numerator,
        this->m_pronount
    };
}

Fraction operator* (int32_t numerator, const Fraction &fraction) noexcept{
    return fraction * numerator;
}

void Fraction::print(void) const {
    std::cout << m_numerator << '/' << m_pronount << std::endl;
}

}   // lab_4;