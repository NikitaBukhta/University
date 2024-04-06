/************************************
 * Laboratory work #4;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *
 * Task 2;                          *
 ************************************
 */

#include "Fraction.hpp"

#include <iostream>

using namespace lab_4;

int main(int argc, char **argv) {
    Fraction f1;
    std::cout << "Input fraction 1: ";
    std::cin >> f1;

    Fraction f2;
    std::cout << "Input fraction 2: ";
    std::cin >> f2;

    std::cout << f1 << " * " << f2 << " is " << (f1 * f2) << std::endl;

    return 0;
}