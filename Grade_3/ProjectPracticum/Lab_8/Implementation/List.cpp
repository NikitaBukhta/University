#include "List.hpp"

#include <memory>

namespace lab_8 {

//---------------------------- Node ----------------------------//

template <typename T>
Node<T>::~Node(void) {
    if (right) {
        delete right;
    }
}

//---------------------------- List ---------------------------//

template <typename T>
List<T>::List(void) : m_size{0}, m_head{nullptr} {
}

template <typename T>
List<T>::List(const List<T> &other) {
    operator=(other);
}

template <typename T>
List<T>::List(const std::initializer_list<T> &init_list) : List() {
    operator=(init_list);
}

template <typename T>
List<T>::~List(void) {
    destroy();
}

template <typename T>
void List<T>::operator= (const List<T> &other) {
    destroy();

    this->m_size = other.m_size;

    if (!other.m_head) {
        return;
    }
    
    m_head = new Node<T>();
    m_head->val = other.m_head->val;

    Node<T> *current_this_node = this->m_head;
    Node<T> *current_other_node = other.m_head;
    while (current_other_node->right) {
        current_this_node->right = new Node<T>();
        current_this_node->right->val = current_other_node->right->val;

        current_this_node->right->left = current_this_node;
        current_this_node = current_this_node->right;
        current_other_node = current_other_node->right;
    }
}

template <typename T>
void List<T>::operator= (const std::initializer_list<T> &init_list) {
    destroy();
    m_size = init_list.size();

    auto init_list_begin = init_list.begin();
    auto init_list_end = init_list.end();
    if (!m_head) {
        m_head = new Node<T>(*init_list_begin);
        ++init_list_begin;
    }

    Node<T> *current_node = m_head->right;
    while (init_list_begin != init_list_end) {
        current_node = new Node<T>(*init_list_begin);
        current_node = current_node->right;
        ++init_list_begin;
    }
}

template <typename T>
T& List<T>::operator[](std::uint64_t index) {
    if (!m_head) {
        m_head = new Node<T>();
        ++m_size;
    }

    Node<T> *current_node = m_head;
    for (; index != 0; --index) {
        if (!current_node->right) {
            current_node->right = new Node<T>();
            ++m_size;
        }

        current_node->right->left = current_node;
        current_node = current_node->right;
    }

    return current_node->val;
}

template <typename T>
void List<T>::destroy(void) {
    if (m_head) {
        delete m_head;
    }
}

template <typename T>
ListIterator<T> List<T>::begin(void) const {
    return {this->m_head};
}

template <typename T>
ListIterator<T> List<T>::end(void) const {
    return {nullptr};
}

template <typename T>
std::size_t List<T>::size(void) const noexcept {
    return m_size;
}

//------------------------ ListIterator ------------------------//

template <typename T>
ListIterator<T>::ListIterator(Node<T> *cur) : m_cur{cur} {

}

template <typename T>
ListIterator<T>& ListIterator<T>::operator++(void) {
    m_cur = m_cur->right;

    return *this;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator--(void) {
    m_cur = m_cur->left;

    return *this;
}

template <typename T>
ListIterator<T> ListIterator<T>::operator++(int) {
    ListIterator<T> ret = *this;
    this->operator++();

    return ret;
}

template <typename T>
ListIterator<T> ListIterator<T>::operator--(int) {
    ListIterator<T> ret = *this;
    this->operator--();

    return ret;
}

template <typename T>
T* ListIterator<T>::operator*(void) const {
    return &m_cur->val;
}

template <typename T>
bool ListIterator<T>::operator==(const ListIterator<T> &other)
{
    return this->m_cur == other.m_cur;
}

template <typename T>
bool ListIterator<T>::operator!=(const ListIterator<T> &other)
{
    return !(this->operator==(other));
}

}   // !lab_8;