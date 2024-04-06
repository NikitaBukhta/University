/************************************
 * Laboratory work #6;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *                       *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB7_MATRIX_HPP
#define BUKHTAMYKYTA_LAB7_MATRIX_HPP

#include "Number.hpp"

#include <array>
#include <vector>

#define __MATRIX_SIZE_BY_SPEC__ 100

namespace lab_7 {

class Matrix : Number {
public:
    Matrix(int64_t number);

    void printMatrixFactorial(void) const noexcept;
    void printMatrix(void) const noexcept;

public:
    std::vector<std::array<int64_t, __MATRIX_SIZE_BY_SPEC__>> m_matrix;
};

}   // !lab_7;

#endif  // !BUKHTAMYKYTA_LAB7_MATRIX_HPP;