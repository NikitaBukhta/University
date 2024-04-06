/************************************
 * Laboratory work #6;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *                       *
 ************************************
 */

#include "Matrix.hpp"

#include <random>
#include <iostream>

using namespace lab_7;

int32_t random(int32_t min, int32_t max) {
    static std::random_device dev;
    static std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max); // distribution in range [1, 6]

    return dist6(rng);
}

int main(int argc, char **argv) {
    Matrix matrix{10};

    for (auto &arr : matrix.m_matrix) {
        for (auto &elem : arr) {
            elem = random(1, 10);
        }
    }

    matrix.printMatrix();
    std::cout << "\n\n-----------------------\n\n" << std::endl;
    matrix.printMatrixFactorial();

    return 0;
}