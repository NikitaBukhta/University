#include "Numbers.hpp"

#include <iostream>

namespace lab_2 {
namespace task_1 {

Numbers::Numbers(int32_t val_1, int32_t val_2) 
    : m_val_1{val_1}, m_val_2{val_2}
{

}

bool Numbers::set(int32_t val_1, int32_t val_2) {
    m_val_1 = val_1;
    m_val_2 = val_2;
    return true;
}

bool Numbers::print(void) {
    std::cout << "Numbers(" << m_val_1 << ", " << m_val_2 << ")\n";
    return true;
}

}   // !task_1;
}   // !lab_2;