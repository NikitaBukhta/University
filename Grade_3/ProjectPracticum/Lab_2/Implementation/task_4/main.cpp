/************************************
 * Laboratory work #2;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *
 * Task 4;                          *
 ************************************
 */

#include "Numbers.hpp"

#include <iostream>

using namespace lab_2::task_4;

int main(int argc, char **argv) {
    Numbers point1;
    point1.setValues(3.0, 4.0, 5.0);
    
    Numbers point2;
    point2.setValues(3.0, 4.0, 5.0);

    if (point1.isEqual(point2))
        std::cout << "point1 and point2 are equals\n";
    else
        std::cout << "point1 and point2 are not equals\n";

    Numbers point3;
    point3.setValues(7.0, 8.0, 9.0);

    if (point1.isEqual(point3))
        std::cout << "point1 and point3 are equals\n";
    else
        std::cout << "point1 and point3 are not equals\n";
    
    return 0;
}