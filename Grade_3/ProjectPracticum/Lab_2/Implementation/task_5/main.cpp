/************************************
 * Laboratory work #2;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *
 * Task 5;                          *
 ************************************
 */

#include "Stack.hpp"

#include <iostream>

using namespace lab_2::task_5;

int main(int argc, char **argv) {
    Stack stack;
    stack.reset();
    
    stack.print();

    stack.push(3);
    stack.push(5);
    stack.push(7);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();
    
    return 0;
}