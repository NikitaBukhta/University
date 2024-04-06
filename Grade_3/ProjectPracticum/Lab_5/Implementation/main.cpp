/************************************
 * Laboratory work #5;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *                       *
 ************************************
 */

#include "Vector"
#include "Matrix"

#include <iostream>

using namespace lab_5;

void print(const Vector<int32_t> &vector) {
    uint64_t size = vector.size();

    for (uint64_t i{0}; i < size; ++i) {
        std::cout << vector[i] << ", ";
    }
    std::cout << std::endl;
}

void print(const Matrix<int32_t> &matrix) {
    uint64_t size = matrix.rows_count();

    for (uint64_t i{0}; i < size; ++i) {
        print(matrix[i]);
    }
}

int main(int argc, char **argv) {
    Vector<int32_t> vector = {1, 2, 3};
    Matrix<int32_t> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::cout << "3 * vector * 3" << std::endl;
    print(3 * vector * 3);
    std::cout << "\n3 * matrix * 3" << std::endl;
    print(3 * matrix * 3);
    std::cout << "\nvector * vector" << std::endl;
    print(vector * vector);
    std::cout << "\nmatrix * matrix" << std::endl;
    print(matrix * matrix);
    std::cout << "\vector * matrix * vector" << std::endl;
    print(vector * matrix * vector);

    return 0;
}