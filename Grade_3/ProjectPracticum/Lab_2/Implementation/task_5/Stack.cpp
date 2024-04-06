#include "Stack.hpp"

#include <iostream>

#include <assert.h>

namespace {
    const int32_t MAX_STACK_SIZE = 10;
}

namespace lab_2 {
namespace task_5 {

Stack::Stack(void) : m_MAX_SIZE{MAX_STACK_SIZE}, m_head{nullptr} {
    m_root = new int32_t[10];
}

Stack::~Stack(void) {
    delete[] m_root;
}

bool Stack::reset(void) {
    m_head = nullptr;
    return true;
}

bool Stack::push(int32_t val) noexcept {
    if (!m_head) {
        m_head = m_root;
    } else if ((m_head - m_root) < m_MAX_SIZE) {
        ++m_head;
    } else {
        std::cout << "nothing" << std::endl;
        return false;
    }

    *m_head = val;
    return true;
}

bool Stack::pop(void) noexcept {
    assert((m_head - m_root) < m_MAX_SIZE && m_head);

    if (--m_head < m_root) {
        m_head = nullptr;
    }

    return true;
}

bool Stack::print(void) const {    
    std::cout << "( ";
    for (int32_t *current = m_root; current <= m_head && m_head; ++current) {
        std::cout << *current << " ";
    }
    std::cout << ")\n";

    return true;
}

}   // !task_5;
}   // !lab_2;