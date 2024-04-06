/************************************
 * Laboratory work #2;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *
 * Task 1;                          *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB_2_TASK_1_NUMBERS
#define BUKHTAMYKYTA_LAB_2_TASK_1_NUMBERS

#include <inttypes.h>

namespace lab_2 {
namespace task_1 {

class Numbers {
public:
    Numbers(int32_t val_1 = 0, int32_t val_2 = 0);
    virtual ~Numbers(void) = default;

    bool set(int32_t val_1, int32_t val_2);

    bool print(void);

private:
    int32_t m_val_1;
    int32_t m_val_2;
};

}   // !task_1;
}   // !lab_2;

#endif  // !BUKHTAMYKYTA_LAB_2_TASK_1_NUMBERS;