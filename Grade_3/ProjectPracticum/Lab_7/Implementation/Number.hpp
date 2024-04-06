/************************************
 * Laboratory work #6;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *                       *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB7_NUMBER_HPP
#define BUKHTAMYKYTA_LAB7_NUMBER_HPP

#include <inttypes.h>

namespace lab_7 {

class Number {
public:
    Number(uint64_t number);
    virtual ~Number(void) = default;
    virtual uint64_t factorial(int64_t val) const noexcept;

protected:
    int64_t m_number;
};

}   // !lab_7;

#endif  // !BUKHTAMYKYTA_LAB7_NUMBER_HPP;