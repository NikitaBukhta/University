/************************************
 * Laboratory work #2;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *
 * Task 1;                          *
 ************************************
 */

#include "Numbers.hpp"

using namespace lab_2::task_1;

int main(int argc, char **argv) {
    Numbers n1;
    n1.set(3, 3);   // Init the object n1 with values 3 : 3;
    Numbers n2{4, 4};

    n1.print();
    n2.print();

    return 0;
}