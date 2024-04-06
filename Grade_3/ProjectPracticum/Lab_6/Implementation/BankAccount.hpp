/************************************
 * Laboratory work #6;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *                       *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB_6_BANKACCOUNT_HPP
#define BUKHTAMYKYTA_LAB_6_BANKACCOUNT_HPP

#include <inttypes.h>
#include <string>

namespace lab_6 {

class BankAccount {
public:
    BankAccount(void);
    BankAccount(uint64_t balance, uint16_t interest_rate);
    virtual ~BankAccount(void) = default;

    /*
     * Getters / setters starts;
     */

    uint64_t balance(void) const noexcept;

    uint16_t interest_rate(void) const noexcept;
    void set_interest_rate(uint16_t val) noexcept;

    /*
     * Getters / setters ends;
     */

    uint64_t calculate_balance_with_interest(void) const noexcept;

    /*
     * Static methods starts;
     */

    /*
     * Class interface starts;
     */

    std::string to_string(void) const;

    /*
     * Class interface ends;
     */

    /* Description:
     * Convert int number to float as std::string;
     */
    static std::string convert_to_floating_string(uint64_t val);

    /*
     * Static methods ends;
     */

protected:
    uint64_t m_balance;

private:
    uint32_t m_id;
    static uint32_t m_id_counter;

    uint16_t m_interest_rate;
};

}   // !lab_6;

#endif  // !BUKHTAMYKYTA_LAB_6_BANKACCOUNT_HPP;