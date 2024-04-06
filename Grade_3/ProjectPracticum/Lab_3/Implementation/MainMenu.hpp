/************************************
 * Laboratory work #3;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB3_MAINMENU_HPP
#define BUKHTAMYKYTA_LAB3_MAINMENU_HPP

#include "IMenu.hpp"
#include "Employee.hpp"

#include <deque>
#include <memory>

namespace lab_3 {

class MainMenu : public IMenu {
private:
    enum class TAB_ENUM {
        ADD_WORKER = 1,
        OUTPUT_WORKER_INFO,
        OUTPUT_WORKER_BONUS_INFO
    };

public:
    MainMenu(void);
    virtual ~MainMenu(void) = default;

    void draw(void) override;

private:
    void init_employees(void);
    void handle_tab(int16_t tab);
    void open_add_worker_submenu(void);
    void output_workers_info(void) const;
    void output_workers_bonus_info(void) const;

private:    
    std::deque<std::shared_ptr<Employee>> m_employees;
};

}   // !lab_3;

#endif  // !BUKHTAMYKYTA_LAB3_MAINMENU_HPP;