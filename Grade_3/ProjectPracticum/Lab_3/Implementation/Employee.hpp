/************************************
 * Laboratory work #3;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB3_EMPLOYEE_HPP
#define BUKHTAMYKYTA_LAB3_EMPLOYEE_HPP

#include "CommonTypes.hpp"

#include <inttypes.h>

namespace lab_3 {

class Employee {
public:
    Employee(common_types::POSITION position = common_types::POSITION::COMMON_SPECIALIST);
    Employee(const common_types::FullName &full_name, common_types::POSITION position = common_types::POSITION::COMMON_SPECIALIST);
    virtual ~Employee(void) = default;

    // Getters starts;

    virtual uint32_t salary(void) const noexcept;
    virtual common_types::POSITION position(void) const noexcept;
    virtual common_types::FullName full_name(void) const;

    // Getters ends;

    // Setters starts;

    virtual void set_salary(uint32_t val) noexcept;
    virtual void set_position(common_types::POSITION val) noexcept;
    virtual void set_full_name(const common_types::FullName &val);
    virtual void set_full_name(common_types::FullName &&val);

    // Setters ends;

private:
    uint32_t m_salary;
    common_types::POSITION m_position;
    common_types::FullName m_full_name;
};

}   // !lab_3;

#endif  // !BUKHTAMYKYTA_LAB3_EMPLOYEE_HPP;