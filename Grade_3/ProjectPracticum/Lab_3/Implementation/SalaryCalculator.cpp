#include "SalaryCalculator.hpp"

namespace lab_3 {

SalaryCalculator* SalaryCalculator::instance(void) {
    static SalaryCalculator instance;
    return &instance;
}

uint32_t SalaryCalculator::calculate(const Employee &employee) const {
    auto salary_rate = m_salaries.find(employee.position());

    if (salary_rate == m_salaries.end()) {
        return 0;
    }

    return salary_rate->second;
}

uint32_t SalaryCalculator::calculate_with_bonus(const Employee &employee, const std::deque<std::shared_ptr<Employee>> employees) const {
    uint64_t monthly_salary{0};
    uint32_t avarage_salary{0};
    uint32_t bonus{0};
    uint32_t employee_salary{employee.salary()};

    for (const auto &empl : employees) {
        monthly_salary += empl->salary();
    }
    avarage_salary = monthly_salary / employees.size();

    employee_salary < avarage_salary 
        ? bonus = employee_salary / 2 
        : bonus = employee_salary / 100 * 30;
    
    return employee_salary + bonus;
}

SalaryCalculator::SalaryCalculator(void) {
    m_salaries[common_types::POSITION::COMMON_SPECIALIST] = 10000;
    m_salaries[common_types::POSITION::FIRST_CATEGORY_SPECIALST] = 12500;
    m_salaries[common_types::POSITION::SECOND_CATEGORY_SPECIALST] = 15000;
    m_salaries[common_types::POSITION::HIGH_CATEGORY_SPECIALIST] = 17500;
    m_salaries[common_types::POSITION::BRANCH_MANAGER] = 20000;
    m_salaries[common_types::POSITION::DIRECTOR] = 22500;
}

}   // !lab_3;