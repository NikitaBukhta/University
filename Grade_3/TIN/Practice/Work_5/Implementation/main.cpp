#include <iostream>
#include <cmath>
#include <vector>

// C = 1,2 ∗ ∑i = 1ci;

// data get from table 6;
struct NetTech {
    int32_t c_min;
    uint64_t vi;      // 8 * speed * 10 ^ x. Convert to bit is required
};

const int16_t HEADER = 368;

double calculate_u5(uint64_t vi) {
    return vi / (1500 * 8 * 1800);
}

float calculate_c(const NetTech net) {
    const double u_5 = calculate_u5(net.vi);
    // std::cout << u_5 << std::endl;
    return net.c_min + u_5 * HEADER;
};

int main(int argc, char **argv) {
    std::vector<NetTech> arr;
    arr = {
        {512, 50LL * 8 * 1000000},
        {25, 256LL * 8 * 1000},
        {128, 2LL * 8 * 1000000},
        {128, 2LL * 8 * 1000000},
        {128, 1LL * 8 * 1000000},
        {8096, 1LL * 8 * 1000000000},
        {32, 100LL * 8 * 1000},
        {512, 2LL * 8 * 1000000},
        {64, 512LL * 8 * 1000},
        {2048, 200LL * 8 * 1000000},
        {10000, 15000LL * 8 * 1000000},
        {32, 15LL * 8 * 1000},
        {32, 10LL * 8 * 1000},
        {128, 100LL * 8 * 1000}
    };

    double sum = 0;

    int i = 0;
    for (const auto &elem : arr) {
        auto cur = calculate_c(elem);
        std::cout << "C" << ++i << ": " << cur << std::endl;
        sum += cur;
    }
    
    // auto answer = 1.2 * sum;
    std::cout << "------------------------------------\n" << "answer = " << answer << std::endl;

    return 0;
}