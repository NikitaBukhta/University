/************************************
 * Laboratory work #5;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *                       *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB_5_MATRIX_HPP
#define BUKHTAMYKYTA_LAB_5_MATRIX_HPP

#include "Vector"
#include <inttypes.h>
#include <initializer_list>

namespace lab_5 {

template <typename T>
class Matrix {
public:
    Matrix(void);
    Matrix(const std::initializer_list<std::initializer_list<T>> &init_matrix);
    Matrix(const Matrix<T> &other);
    Matrix(Matrix<T> &&other);
    Matrix(const Vector<Vector<T>> &matrix);
    virtual ~Matrix(void) = default;

    void operator= (const std::initializer_list<std::initializer_list<T>> &init_matrix);
    void operator= (const Matrix<T> &other);
    void operator= (Matrix<T> &&other);
    void operator= (const Vector<Vector<T>> &matrix);
    Vector<T>& operator[] (uint64_t index) const noexcept;
    
    /* Description: 
     *  Multiple matrix to each other;
     *
     * Return values:
     *  If count of colums of the first matrix is
     * not equals to count of rows of the second matrix
     * (arg other), !!! the empty matrix should be returned !!!;
     * 
     */
    Matrix<T> operator* (const Matrix<T> &other) const;
    Matrix<T> operator* (const Vector<T> &vector) const;
    template <typename U>   // to remove the warning during compilation;
    friend Matrix<U> operator* (const Vector<U> &vector, const Matrix<U> &matrix);
    Matrix<T> operator* (int32_t val) const;
    template <typename U>   // to remove the warning during compilation;
    friend Matrix<U> operator* (int32_t val, const Matrix<U> &other);

    uint64_t rows_count(void) const noexcept;
    uint64_t colums_count(void) const noexcept;

    void resize_rows(uint64_t size);
    void resize_colums(uint64_t size);

private:
    Vector<Vector<T>> m_matrix;
    uint64_t m_colums_count;
};

}   // !lab_5;

#endif  // !BUKHTAMYKYTA_LAB_5_MATRIX_HPP;