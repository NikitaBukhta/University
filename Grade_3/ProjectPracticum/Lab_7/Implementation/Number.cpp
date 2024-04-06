#include "Number.hpp"

namespace lab_7 {

Number::Number(uint64_t number) : m_number(number) {
    
}

uint64_t Number::factorial(int64_t val) const noexcept {
    if (val <= 0) {
        return 0;
    }

    int64_t ret{1};

    for (int64_t i{2}; i < val; ++i) {
        ret *= i;
    }

    return ret;
}

};