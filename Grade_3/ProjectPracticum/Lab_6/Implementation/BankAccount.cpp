#include "BankAccount.hpp"
#include "Config.hpp"

namespace lab_6 {

uint32_t BankAccount::m_id_counter = 0;

BankAccount::BankAccount(void) : BankAccount(0, 0) {
}

BankAccount::BankAccount(uint64_t balance, uint16_t interest_rate)
    : m_balance{balance}, m_interest_rate{interest_rate}
{
    m_id = m_id_counter++;
}

/*
 * Getters / setters starts;
 */

uint64_t BankAccount::balance(void) const noexcept {
    return m_balance;
}

uint16_t BankAccount::interest_rate(void) const noexcept {
    return m_interest_rate;
}

void BankAccount::set_interest_rate(uint16_t val) noexcept {
    m_interest_rate = val;
}

/*
 * Getters / setters ends;
 */

uint64_t BankAccount::calculate_balance_with_interest(void) const noexcept {
    return m_balance / config::FULL_PERCENT * m_interest_rate / config::NUMBER_CONVERTOR_DEVIDER + m_balance;
}

std::string BankAccount::to_string(void) const {
    std::string ret{std::move(convert_to_floating_string(m_balance))};

    return std::move(ret);
}

/*
 * Static methods starts;
 */

std::string BankAccount::convert_to_floating_string(uint64_t val) {
    std::string ret{std::move(std::to_string(val))};
    ret.insert(ret.end() - config::FLOATING_NUMBERS_COUNT, config::FLOATING_DELIMITER);
    return std::move(ret);
}

/*
 * Static methods ends;
 */

}   // !lab_6;