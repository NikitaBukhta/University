/************************************
 * Laboratory work #3;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB3_SALARYCALCULATOR_HPP
#define BUKHTAMYKYTA_LAB3_SALARYCALCULATOR_HPP

#include "Employee.hpp"

#include <unordered_map>
#include <deque>
#include <memory>
#include <inttypes.h>

namespace lab_3 {

class SalaryCalculator {
public:
    static SalaryCalculator* instance(void);
    uint32_t calculate(const Employee &employee) const;
    uint32_t calculate_with_bonus(const Employee &employee, const std::deque<std::shared_ptr<Employee>> employees) const;

private:
    SalaryCalculator(void);

private:
    std::unordered_map<common_types::POSITION, int32_t> m_salaries;
};

}   // !lab_3;

#endif  // !BUKHTAMYKYTA_LAB3_SALARYCALCULATOR_HPP;