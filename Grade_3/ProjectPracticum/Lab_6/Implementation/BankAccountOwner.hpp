/************************************
 * Laboratory work #6;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *                       *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB_6_BANKACCOUNTOWNER_HPP
#define BUKHTAMYKYTA_LAB_6_BANKACCOUNTOWNER_HPP

#include "Owner.hpp"
#include "BankAccount.hpp"

#include <inttypes.h>
#include <string>

namespace lab_6 {

class BankAccountOwner : public Owner, public BankAccount {
public:
    // BankAccountOwner(void) = default;
    BankAccountOwner(uint64_t max_withdraw_sum, uint64_t min_balance, const std::string &password);
    BankAccountOwner(const Owner::Passport &m_passport, uint64_t balance, uint16_t interest_rate, uint64_t max_withdraw_sum, 
        uint64_t min_balance, const std::string &password);
    BankAccountOwner(const Owner &owner, const BankAccount &account, uint64_t max_withdraw_sum, uint64_t min_balance, const std::string &password);
    virtual ~BankAccountOwner(void) = default;

    /*
     * Getters/Setters starts;
     */

    uint64_t max_witdraw_sum(void) const noexcept;
    uint64_t min_balance(void) const noexcept;
    void set_password(const std::string &new_password);

    /*
     * Getters/Setters ends;
     */

    /*
     * Class interface starts;
     */

    std::string to_string(void) const;
    void cash_in(uint64_t sum) noexcept;
    
    /* Description:
     *  Method change the balance of the owner account. We cannot to withdraw more money,
     * then the balance could have after operation. The balance should have more than m_MIN_BALANCE
     * money for this operation or not more than daily limit (m_MAX_WITHDRAW_SUM);
     * 
     * Args:
     *  sum - count of money user want to withdraw. The last 2 numbers are kopecs value.
     * 
     * Return value.
     *  true - operation was successfull.
     *  false - sum is not valid;
     */
    bool withdraw(uint64_t sum) noexcept;

    /*
     * Class interface ends;
     */

private:
    const uint64_t m_MAX_WITHDRAW_SUM;
    const uint64_t m_MIN_BALANCE;
    std::string m_password;
};

}   // !lab_6;

#endif  // !BUKHTAMYKYTA_LAB_6_BANKACCOUNTOWNER_HPP;