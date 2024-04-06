/************************************
 * Laboratory work #4;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *
 * Task 2;                          *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB_4_TASK_1_FRACTION_HPP
#define BUKHTAMYKYTA_LAB_4_TASK_1_FRACTION_HPP

#include <istream>
#include <ostream>

namespace lab_4 {

class Fraction {
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int numerator = 0, int decominator = 1);

    friend Fraction operator* (const Fraction &f1, const Fraction &f2);
    friend Fraction operator* (const Fraction &f1, int value);
    friend Fraction operator* (int value, const Fraction &f1);
    friend std::istream& operator>> (std::istream & in, Fraction &f1);
    friend std::ostream& operator<< (std::ostream & out, const Fraction &f1);

    static int nod(int a, int b);

    void reduce();
    void print();
};

}   // !lab_4;

#endif  // !BUKHTAMYKYTA_LAB_4_TASK_1_FRACTION_HPP;