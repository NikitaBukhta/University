/************************************
 * Laboratory work #4;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *
 * Task 1;                          *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB_4_TASK_1_FRACTION_HPP
#define BUKHTAMYKYTA_LAB_4_TASK_1_FRACTION_HPP

#include <inttypes.h>

namespace lab_4 {

class Fraction {
public:
    explicit Fraction(int32_t numerator = 0, int32_t pronount = 0);
    Fraction operator* (const Fraction &other) const noexcept;
    Fraction operator* (int32_t numerator) const noexcept;
    friend Fraction operator* (int32_t numerator, const Fraction &fraction) noexcept;

    void print(void) const;
private:
    int32_t m_numerator;
    int32_t m_pronount;
};

}   // !lab_4;

#endif  // !BUKHTAMYKYTA_LAB_4_TASK_1_FRACTION_HPP;