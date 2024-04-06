/************************************
 * Laboratory work #4;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *
 * Task 1;                          *
 ************************************
 */

#include "Fraction.hpp"

#include <utility>
#include <iostream>

using namespace lab_4;

void do_fragment_a(void) {
    std::cout << "Start task 1(a):" << std::endl;
    Fraction f1{1, 4};
    f1.print();

    Fraction f2{1, 2};
    f2.print();
}

void do_fragment_b(void) {
    std::cout << "Start task 1(b):" << std::endl;
    Fraction f1{3, 4};
    f1.print();

    Fraction f2{2, 7};
    f2.print();

    Fraction f3{f1 * f2};
    f3.print();

    Fraction f4{f1 * 3};
    f4.print();

    Fraction f5{3 * f2};
    f5.print();

    Fraction f6{Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4}};
    f6.print();
}

int main(int argc, char **argv) {
    do_fragment_a();
    do_fragment_b();

    return 0;
}