/************************************
 * Laboratory work #2;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *
 * Task 5;                          *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB_2_TASK_5_STACK
#define BUKHTAMYKYTA_LAB_2_TASK_5_STACK

#include <inttypes.h>

namespace lab_2 {
namespace task_5 {

class Stack {
public:
    Stack(void);
    virtual ~Stack(void);

    bool reset(void);
    bool push(int32_t val) noexcept;
    bool pop(void) noexcept;
    bool print(void) const;

private:
    const int32_t m_MAX_SIZE;
    int32_t *m_root;
    int32_t *m_head;
};

}   // !task_5;
}   // !lab_2;

#endif  // !BUKHTAMYKYTA_LAB_2_TASK_5_STACK;