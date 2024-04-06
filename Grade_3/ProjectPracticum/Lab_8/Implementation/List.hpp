#ifndef LAB_8_PROJECTPRACTICUM_BUKHTAMYKYTA_SE304_LIST_HPP
#define LAB_8_PROJECTPRACTICUM_BUKHTAMYKYTA_SE304_LIST_HPP

#include <initializer_list>
#include <cinttypes>

namespace lab_8 {

template <typename T>
class ListIterator;

template <typename T>
struct Node {
    ~Node(void);

    T val;
    Node *left;
    Node *right;
};

template <typename T>
class List final {
    friend class ListIterator<T>;

public:
    List(void);
    List(const List<T> &other);
    List(const std::initializer_list<T> &init_list);
    ~List(void);

    void operator= (const List<T> &other);
    void operator= (const std::initializer_list<T> &init_list);

    T& operator[](std::uint64_t index);

    ListIterator<T> begin(void) const;
    ListIterator<T> end(void) const;

    std::size_t size(void) const noexcept;

private:
    void destroy(void);

private:
    Node<T> *m_head;
    std::size_t m_size;
};

template <typename T>
class ListIterator {
public:
    ListIterator(Node<T> *cur = nullptr);

    /* Description:
     *  Prefix operator;
     */
    ListIterator<T>& operator++(void);
    ListIterator<T>& operator--(void);

    /* Description:
     *  Postfix operator;
     */
    ListIterator<T> operator++(int);
    ListIterator<T> operator--(int);

    bool operator==(const ListIterator<T> &other);
    bool operator!=(const ListIterator<T> &other);

    T* operator*(void) const;

private:
    Node<T> *m_cur;
};

}   // !lab_8;

#endif  // !LAB_8_PROJECTPRACTICUM_BUKHTAMYKYTA_SE304_LIST_HPP;