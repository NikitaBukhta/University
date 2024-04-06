/************************************
 * Laboratory work #5;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *                       *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB_5_VECTOR_HPP
#define BUKHTAMYKYTA_LAB_5_VECTOR_HPP

#include <inttypes.h>
#include <initializer_list>

namespace lab_5 {

#define __COMMON_VECTOR_LIST_SIZE__ 10

template <typename T>
class Vector {
public:
    Vector(void);
    Vector(const std::initializer_list<T> &init_list);
    Vector(const Vector<T> &other);
    Vector(Vector<T> &&other);
    virtual ~Vector(void);

    void operator= (const std::initializer_list<T> &init_list);
    void operator= (const Vector<T> &other);
    void operator= (Vector<T> &&other);
    T& operator[] (uint64_t index) const noexcept;

    /* Description:
     * Multiple vectors to each other.
     *
     * Return values:
     * Return vector with min vector size between two vector;
     */
    Vector<T> operator* (const Vector<T> &other) const;
    Vector<T> operator* (int32_t val) const;
    template <typename U>   // to remove the warning during compilation.
    friend Vector<U> operator* (int32_t val, const Vector<U> &other);

    uint64_t size(void) const noexcept;
    void resize(uint64_t size);
    void clear(void);

private:
    T *m_dynamic_array = nullptr;
    uint64_t m_size;
    uint64_t m_inited_size;
};

}   // !lab_5;

#endif  // !BUKHTAMYKYTA_LAB_5_VECTOR_HPP;