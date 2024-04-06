#include "Vector.hpp"

#include <cstring>
#include <utility>
#include <algorithm>

namespace lab_5 {

template <typename T>
Vector<T>::Vector(void)
{
    m_size = 0;
    m_inited_size = __COMMON_VECTOR_LIST_SIZE__;
    m_dynamic_array = new T[m_inited_size];
}

template <typename T>
Vector<T>::Vector(const std::initializer_list<T> &init_list) {
    operator=(init_list);
}

template <typename T>
Vector<T>::Vector(const Vector<T> &other) {
    operator=(other);
}

template <typename T>
Vector<T>::Vector(Vector<T> &&other) {
    operator=(std::move(other));
}

template <typename T>
Vector<T>::~Vector(void) {
    clear();
}

template <typename T>
void Vector<T>::operator= (const std::initializer_list<T> &init_list) {
    clear();

    m_size = init_list.size();
    m_inited_size = m_size + __COMMON_VECTOR_LIST_SIZE__;
    m_dynamic_array = new T[m_inited_size];
    uint64_t i{0};
    for (auto init_elem : init_list) {
        m_dynamic_array[i++] = init_elem;
    }
}

template <typename T>
void Vector<T>::operator= (const Vector<T> &other) {
    clear();

    this->m_size = other.m_size;
    this->m_inited_size = this->m_size + __COMMON_VECTOR_LIST_SIZE__;
    this->m_dynamic_array = new T[this->m_inited_size];

    for (uint64_t i{0}; i < this->m_size; ++i) {
        this->m_dynamic_array[i] = other.m_dynamic_array[i];
    }
}

template <typename T>
void Vector<T>::operator= (Vector<T> &&other) {
    this->m_dynamic_array = other.m_dynamic_array;
    this->m_inited_size = other.m_inited_size;
    this->m_size = other.m_size;

    other.m_dynamic_array = nullptr;
    other.m_inited_size = 0;
    other.m_size = 0;
}

template <typename T>
T& Vector<T>::operator[] (uint64_t index) const noexcept {
    return m_dynamic_array[index];
}

template <typename T>
Vector<T> Vector<T>::operator* (const Vector<T> &other) const {
    uint64_t ret_vector_size = std::min(this->size(), other.size());
    Vector<T> ret;
    ret.resize(ret_vector_size);

    for (uint64_t i{0}; i < ret_vector_size; ++i) {
        ret[i] = this->m_dynamic_array[i] * other.m_dynamic_array[i];
    }

    return std::move(ret);
}

template <typename T>
Vector<T> Vector<T>::operator* (int32_t val) const {
    Vector<T> ret{*this};
    
    for (uint64_t i{0}; i < ret.m_size; ++i) {
        ret[i] = this->m_dynamic_array[i] * val;
    }

    return std::move(ret);
}

template <typename U>
Vector<U> operator* (int32_t val, const Vector<U> &other) {
    return std::move(other.operator*(val));
}

template <typename T>
uint64_t Vector<T>::size(void) const noexcept {
    return m_size;
}

template <typename T>
void Vector<T>::resize(uint64_t size) {
    if (m_size == size) {
        return;
    }

    T *new_dynamic_array = new T[size];
    
    uint64_t min_size = std::min(size, m_size);
    uint64_t max_size = std::max(size, m_size);
    uint64_t i{0};
    for (; i < min_size; ++i) {
        new_dynamic_array[i] = m_dynamic_array[i];
    }
    for (; i < max_size; ++i) {
        new_dynamic_array[i] = T{};
    }

    clear();
    m_dynamic_array = new_dynamic_array;
    m_inited_size = m_size = size;
}

template <typename T>
void Vector<T>::clear(void) {
    if (m_dynamic_array) {
        delete[] m_dynamic_array;
        m_dynamic_array = nullptr;
    }
}

}   // !lab_5;