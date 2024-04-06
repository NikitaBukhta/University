#include "List"

#include <iostream>

using namespace lab_8;

template <typename T>
void print(const List<T> &list) {
    for (const auto &item : list) {
        std::cout << *item << ", ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    List<std::int32_t> list;

    list[3] = 8;
    list[5] = 12;

    std::cout << "-------- LIST --------" << std::endl;
    print(list);
    list[2] = 2;

    List<std::int32_t> list_2{list};
    List<std::int32_t> list_3;
    list_3 = list_2;

    std::cout << "-------- LIST 2 --------" << std::endl;
    print(list_2);
    std::cout << "-------- LIST 3 --------" << std::endl;
    print(list_3);

    std::cout << "size of list 1/2/3:\t" << list.size() << " / " << list_2.size() << " / " << list_3.size() << std::endl;

    return 0;
}