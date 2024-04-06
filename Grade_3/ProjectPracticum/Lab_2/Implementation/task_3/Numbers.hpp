/************************************
 * Laboratory work #2;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *
 * Task 3;                          *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB_2_TASK_3_NUMBERS
#define BUKHTAMYKYTA_LAB_2_TASK_3_NUMBERS

namespace lab_2 {
namespace task_3 {

class Numbers {
public:
    Numbers(void) = default;
    virtual ~Numbers(void) = default;

    bool setValues(double a, double b, double c) noexcept;
    bool print(void) const;

private:
    double m_a;
    double m_b;
    double m_c;
};

}   // !task_3;
}   // !lab_2;

#endif  // !BUKHTAMYKYTA_LAB_2_TASK_3_NUMBERS;