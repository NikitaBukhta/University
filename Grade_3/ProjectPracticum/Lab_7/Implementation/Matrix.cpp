#include "Matrix.hpp"

#include <iostream>

namespace lab_7 {

Matrix::Matrix(int64_t number) : Number(number) {
    m_matrix.resize(number);
}

void Matrix::printMatrixFactorial(void) const noexcept {
    for (const auto &arr : m_matrix) {
        std::cout << "| ";
        for (const auto &elem : arr) {
            std::cout << this->factorial(elem) << ", ";
        }
        std::cout << "|" << std::endl;
    }
}

void Matrix::printMatrix(void) const noexcept {
    for (const auto &arr : m_matrix) {
        std::cout << "| ";
        for (const auto &elem : arr) {
            std::cout << elem << ", ";
        }
        std::cout << "|" << std::endl;
    }
}

}   // !lab_7;