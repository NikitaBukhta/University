#include "Matrix.hpp"

#include <algorithm>

namespace lab_5 {

template <typename T>
Matrix<T>::Matrix(void)
    : m_colums_count{0}
{

}

template <typename T>
Matrix<T>::Matrix(const std::initializer_list<std::initializer_list<T>> &init_matrix) {
    operator=(init_matrix);
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T> &other) {
    operator=(other);
}

template <typename T>
Matrix<T>::Matrix(Matrix<T> &&other) {
    operator=(std::move(other));
}

template <typename T>
Matrix<T>::Matrix(const Vector<Vector<T>> &matrix) {
    operator=(matrix);
}

template <typename T>
void Matrix<T>::operator= (const std::initializer_list<std::initializer_list<T>> &init_matrix) {
    m_colums_count = 0;
    m_matrix.clear();
    m_matrix.resize(init_matrix.size());
    uint64_t i{0};
    for (auto init_list : init_matrix) {
        m_colums_count = std::max(init_list.size(), m_colums_count);
        m_matrix[i++] = init_list;
    }
}

template <typename T>
void Matrix<T>::operator= (const Matrix<T> &other) {
    this->m_matrix = other.m_matrix;
    this->m_colums_count = other.m_colums_count;
}

template <typename T>
void Matrix<T>::operator= (Matrix<T> &&other) {
    this->m_colums_count = other.m_colums_count;
    this->m_matrix = std::move(other.m_matrix);

    other.m_colums_count = 0;
}

template <typename T>
void Matrix<T>::operator= (const Vector<Vector<T>> &matrix) {
    m_colums_count = 0;
    m_matrix = matrix;
    uint64_t matrix_size = matrix.size();
    for (uint64_t i{0}; i < matrix_size; ++i) {
        m_colums_count = std::max(m_colums_count, matrix[i].size());
    }
}

template <typename T>
Vector<T>& Matrix<T>::operator[] (uint64_t index) const noexcept {
    return m_matrix[index];
}

template <typename T>
Matrix<T> Matrix<T>::operator* (const Matrix<T> &other) const {
    uint64_t other_rows_count = other.rows_count();
    if (m_colums_count != other_rows_count) {
        return {};
    }

    Matrix<T> ret;
    uint64_t this_rows_count = rows_count();
    ret.resize_rows(this_rows_count);
    ret.resize_colums(other.m_colums_count);
    T filling_value{0};

    for (uint64_t this_i{0}; this_i < this_rows_count; ++this_i) {
        for (uint64_t other_j{0}; other_j < other.m_colums_count; ++other_j) {
            // m_colums_count == other_rows_cout, so it is a general (common) size of both matrix;
            for (uint64_t general_index{0}; general_index < m_colums_count; ++general_index) {
                filling_value += this->m_matrix[this_i][general_index] * other.m_matrix[general_index][other_j];
            }
            ret[this_i][other_j] = filling_value;
            filling_value = 0;
        }
    }

    return std::move(ret);
}

template <typename T>
Matrix<T> Matrix<T>::operator* (const Vector<T> &vector) const {
    if (this->m_colums_count != vector.size()) {
        return {};
    }

    Matrix<T> ret;
    ret.resize_rows(rows_count());
    ret.m_colums_count = this->m_colums_count;

    for (uint64_t i{0}; i < this->m_colums_count; ++i) {
        ret[i] = std::move(this->m_matrix[i] * vector);
    }
    return std::move(ret);
}

template <typename U>   // to remove the warning during compilation;
Matrix<U> operator* (const Vector<U> &vector, const Matrix<U> &matrix) {
    return std::move(matrix.operator*(vector));
}

template <typename T>
Matrix<T> Matrix<T>::operator* (int32_t val) const {
    return std::move(Matrix<T>{m_matrix * val});
}

template <typename U>
Matrix<U> operator* (int32_t val, const Matrix<U> &other) {
    return std::move(other.operator*(val));
}

template <typename T>
uint64_t Matrix<T>::rows_count(void) const noexcept {
    return m_matrix.size();
}

template <typename T>
uint64_t Matrix<T>::colums_count(void) const noexcept {
    return m_colums_count;
}

template <typename T>
void Matrix<T>::resize_rows(uint64_t size) {
    uint64_t matrix_size = m_matrix.size();
    if (matrix_size == size) {
        return;
    }
    m_matrix.resize(size);

    // If new rows count > original size, we should to extend new lines;
    if (matrix_size < size) {
        for (uint64_t i{matrix_size}; i < size; ++i) {
            m_matrix[i].resize(m_colums_count);
        }
    }
}

template <typename T>
void Matrix<T>::resize_colums(uint64_t size) {
    uint64_t matrix_size = m_matrix.size();
    m_colums_count = size;
    for (uint64_t i{0}; i < matrix_size; ++i) {
        m_matrix[i].resize(size);
    }
}

}   // !lab_5;