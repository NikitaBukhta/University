#include "MainMenu.hpp"
#include "SalaryCalculator.hpp"

#include <iostream>
#include <limits>

namespace lab_3 {

MainMenu::MainMenu(void) {
    init_employees();
}

void MainMenu::draw(void) {
    static int16_t tab{0};
    std::cout << "1) Add worker;" << std::endl;
    std::cout << "2) Output worker info;"  << std::endl;
    std::cout << "3) Output worker info with bonuses;" << std::endl;
    std::cout << "Input: "; std::cin >> tab;
    handle_tab(tab);
}

void MainMenu::init_employees(void) {
    m_employees.resize(10);

    m_employees[0] = std::make_shared<Employee>(std::move(common_types::FullName{"Worker", "#1"}), 
        common_types::POSITION::COMMON_SPECIALIST);
    m_employees[1] = std::make_shared<Employee>(std::move(common_types::FullName{"Worker", "#2"}), 
        common_types::POSITION::COMMON_SPECIALIST);
    m_employees[2] = std::make_shared<Employee>(std::move(common_types::FullName{"Worker", "#3"}), 
        common_types::POSITION::COMMON_SPECIALIST);
    m_employees[3] = std::make_shared<Employee>(std::move(common_types::FullName{"Worker", "#4"}), 
        common_types::POSITION::FIRST_CATEGORY_SPECIALST);
    m_employees[4] = std::make_shared<Employee>(std::move(common_types::FullName{"Worker", "#5"}), 
        common_types::POSITION::FIRST_CATEGORY_SPECIALST);
    m_employees[5] = std::make_shared<Employee>(std::move(common_types::FullName{"Worker", "#6"}), 
        common_types::POSITION::SECOND_CATEGORY_SPECIALST);
    m_employees[6] = std::make_shared<Employee>(std::move(common_types::FullName{"Worker", "#7"}), 
        common_types::POSITION::SECOND_CATEGORY_SPECIALST);
    m_employees[7] = std::make_shared<Employee>(std::move(common_types::FullName{"Worker", "#8"}), 
        common_types::POSITION::HIGH_CATEGORY_SPECIALIST);
    m_employees[8] = std::make_shared<Employee>(std::move(common_types::FullName{"Worker", "#9"}), 
        common_types::POSITION::BRANCH_MANAGER);
    m_employees[9] = std::make_shared<Employee>(std::move(common_types::FullName{"Worker", "#10"}), 
        common_types::POSITION::DIRECTOR);
}

void MainMenu::handle_tab(int16_t tab) {
    switch(static_cast<TAB_ENUM>(tab)) {
    case TAB_ENUM::ADD_WORKER:
        open_add_worker_submenu();
        break;
    case TAB_ENUM::OUTPUT_WORKER_INFO:
        output_workers_info();
        break;
    case TAB_ENUM::OUTPUT_WORKER_BONUS_INFO:
        output_workers_bonus_info();
        break;
    default:
        std::wcout << "Unknown value!" << std::endl;
    }

    this->draw();
}

void MainMenu::open_add_worker_submenu(void) {
    common_types::FullName full_name;
    uint16_t position;

    std::cout << "Input First Name:\n"; 
    std::getline(std::cin, full_name.first_name).ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Input Second Name:\n"; 
    std::getline(std::cin, full_name.second_name);
    std::cout << "Input Middle Name:\n"; 
    std::getline(std::cin, full_name.middle_name);
    do {    // Input position number;
        std::cout << "Input position list:" << std::endl
        << "0 - COMMON_SPECIALIST" << std::endl
        << "1 - FIRST_CATEGORY_SPECIALST" << std::endl
        << "2 - SECOND_CATEGORY_SPECIALST" << std::endl
        << "3 - HIGH_CATEGORY_SPECIALIST" << std::endl
        << "4 - BRANCH_MANAGER" << std::endl
        << "5 - DIRECTOR" << std::endl
        << "Input: ";
    std::cin >> position;
    }   while (position >= static_cast<uint16_t>(common_types::POSITION::SIZE));

    m_employees.push_back(std::make_shared<Employee>(full_name, static_cast<common_types::POSITION>(position)));
}

void MainMenu::output_workers_info(void) const{
    for (const auto &item : m_employees) {
        std::cout << item->full_name() << '\t' << common_types::to_string(item->position())
            << "\tsalary: " << item->salary() << std::endl;
    }
}

void MainMenu::output_workers_bonus_info(void) const{
    auto salary_calculator = SalaryCalculator::instance();
    
    for (const auto &item : m_employees) {
        std::cout << item->full_name() << '\t' << common_types::to_string(item->position())
            << "\tsalary with bonus: " << salary_calculator->calculate_with_bonus(*item, m_employees) << std::endl;
    }
}

}   // !lab_3;