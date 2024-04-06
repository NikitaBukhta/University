#include "Employee.hpp"
#include "SalaryCalculator.hpp"

namespace lab_3 {

Employee::Employee(common_types::POSITION position)
    : Employee({}, position)
{

}

Employee::Employee(const common_types::FullName &full_name, common_types::POSITION position)
    : m_full_name(full_name), m_position(position)
{
    auto salary_calculator = SalaryCalculator::instance();
    this->set_salary(salary_calculator->calculate(*this));
}

// Getters starts;

uint32_t Employee::salary(void) const noexcept {
    return m_salary;
}

common_types::POSITION Employee::position(void) const noexcept {
    return m_position;
}

common_types::FullName Employee::full_name(void) const {
    return m_full_name;
}

// Getters ends;

// Setters starts;

void Employee::set_salary(uint32_t val) noexcept {
    m_salary = val;
}

void Employee::set_position(common_types::POSITION val) noexcept {
    m_position = val;
}

void Employee::set_full_name(const common_types::FullName &val) {
    m_full_name = val;
}

void Employee::set_full_name(common_types::FullName &&val) {
    m_full_name = std::move(val);
}

// Setters ends;

}   // !lab_3;