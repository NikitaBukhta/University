/************************************
 * Laboratory work #6;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *                       *
 ************************************
 */

#include "BankAccount.hpp"
#include "Owner.hpp"
#include "BankAccountOwner.hpp"

#include <iostream>
#include <string>

using namespace lab_6;

std::string get_withdraw_output_information(BankAccountOwner &owner, uint64_t sum) {
    std::string ret;

    if (!owner.withdraw(sum)) {
        auto max_withdraw_sum = owner.max_witdraw_sum();
        auto min_balance_sum = owner.min_balance();
        auto balance = owner.balance();
        ret = std::string{"Warning! You want to withdraw more than you can do by your account limit!\nWithdraw sum: "}
            + std::to_string(sum) + "\nCurrent balance: " + std::to_string(balance)
            + "\nMax withdraw daily sum: " + std::to_string(max_withdraw_sum)
            + "\nMin sum should be left on the account: " + std::to_string(min_balance_sum);
    } else {
        ret = "Operation successfull!";
    }

    return ret;
}

int main(int argc, char **argv) {
    Owner::Passport init_passport{Owner::FullName{"Bill", "Gates"}, "1234", "123456789"};
    Owner owner{init_passport};
    BankAccount bank_account(30000, 300);
    BankAccountOwner balance_account_owner(owner, bank_account, 50000, 500, "EC123456");
    
    std::cout << bank_account.convert_to_floating_string(10000) << "\n\n";
    std::cout << owner.to_string() << "\n\n";
    std::cout << balance_account_owner.to_string() << "\n\n";
    std::cout << get_withdraw_output_information(balance_account_owner, 50100) << "\n\n";
    std::cout << get_withdraw_output_information(balance_account_owner, 40000) << "\n\n";
    std::cout << get_withdraw_output_information(balance_account_owner, 30000) << "\n\n";
    std::cout << get_withdraw_output_information(balance_account_owner, 25000) << std::endl;

    return 0;
}