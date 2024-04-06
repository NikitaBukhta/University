/************************************
 * Laboratory work #2;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *
 * Task 4;                          *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB_2_TASK_4_NUMBERS
#define BUKHTAMYKYTA_LAB_2_TASK_4_NUMBERS

namespace lab_2 {
namespace task_4 {

class Numbers {
public:
    Numbers(void) = default;
    virtual ~Numbers(void) = default;

    bool isEqual(const Numbers &other) const;
    bool setValues(double a, double b, double c) noexcept;
    bool print(void) const;

private:
    double m_a;
    double m_b;
    double m_c;
};

}   // !task_4;
}   // !lab_2;

#endif  // !BUKHTAMYKYTA_LAB_2_TASK_4_NUMBERS;