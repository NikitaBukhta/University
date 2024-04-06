#include "BankAccountOwner.hpp"
#include "Config.hpp"

namespace lab_6 {

BankAccountOwner::BankAccountOwner(uint64_t max_withdraw_sum, uint64_t min_balance, const std::string &password)
    : m_MAX_WITHDRAW_SUM{max_withdraw_sum}, m_MIN_BALANCE{min_balance}
{

}

BankAccountOwner::BankAccountOwner(const Owner::Passport &passport, uint64_t balance, uint16_t interest_rate, uint64_t max_withdraw_sum, 
    uint64_t min_balance, const std::string &password)
        : BankAccountOwner(Owner{passport}, BankAccount{balance, interest_rate}, max_withdraw_sum, min_balance, password)
{

}

BankAccountOwner::BankAccountOwner(const Owner &owner, const BankAccount &account, uint64_t max_withdraw_sum, uint64_t min_balance, const std::string &password)
    : Owner{owner}, BankAccount(account), m_MAX_WITHDRAW_SUM{max_withdraw_sum}, m_MIN_BALANCE{min_balance}, m_password{password}
{

}

/*
 * Getters/Setters starts;
 */

uint64_t BankAccountOwner::max_witdraw_sum(void) const noexcept {
    return m_MAX_WITHDRAW_SUM;
}

uint64_t BankAccountOwner::min_balance(void) const noexcept {
    return m_MIN_BALANCE;
}

void BankAccountOwner::set_password(const std::string &val) {
    m_password = val;
}

/*
 * Getters/Setters starts;
 */

/*
 * Class interface starts;
 */

std::string BankAccountOwner::to_string(void) const {
    return std::move(Owner::to_string() + config::DATA_DELIMITER_STRING + BankAccount::to_string());
}

void BankAccountOwner::cash_in(uint64_t sum) noexcept {
    m_balance += sum;
}

bool BankAccountOwner::withdraw(uint64_t sum) noexcept {
    if (sum > m_MAX_WITHDRAW_SUM || sum > m_balance || (m_balance - sum) < m_MIN_BALANCE) {
        return false;
    }

    m_balance -= sum;
    return true;
}

/*
 * Class interface ends;
 */

}   // !lab_6;