#include "Owner.hpp"
#include "Config.hpp"

#include <array>
#include <algorithm>
#include <numeric>

namespace lab_6 {

/*
 * Struct FullNmae starts;
 */

Owner::FullName::FullName(std::string init_first_name, std::string init_second_name, std::string init_middle_name)
    : first_name{init_first_name}, second_name{init_second_name}, middle_name{init_middle_name}
{

}

bool Owner::FullName::operator== (const FullName &other) const {
    return this->middle_name == other.middle_name && this->second_name == other.second_name && this->first_name == other.first_name;
}

bool Owner::FullName::operator!= (const FullName &other) const {
    return !this->operator==(other);
}

std::string Owner::FullName::to_string(void) const {
    // 3 - is a count of the string vars. We need it to add the ' ' to the string;
    std::array<const std::string*, 3> init_list = {&second_name, &first_name, &middle_name};
    std::string ret = std::move(std::accumulate(init_list.begin(), init_list.end(), std::string{}, [](std::string &sum, const std::string *elem) {
        if (!sum.empty()) {
            sum.push_back(' ');
        }
        return std::move(sum + *elem);
    }));

    return std::move(ret);
}

/*
 * Struct FullNmae ends;
 */

Owner::Passport::Passport(FullName init_full_name, std::string init_series, std::string init_number)
    : full_name{init_full_name}, series{init_series}, number{init_number}
{

}
bool Owner::Passport::operator== (const Passport &other) const
{
    return this->series == other.series && this->number == other.number;
}

std::string Owner::Passport::to_string(void) const {
    std::string string_full_name{std::move(full_name.to_string())};
    std::array<const std::string*, 3> init_list = {&string_full_name, &series, &number};

    std::string ret = std::move(std::accumulate(init_list.begin(), init_list.end(), std::string{}, [](std::string &sum, const std::string *elem) {
        sum.push_back(' ');
        return std::move(sum + *elem);
    }));

    return std::move(ret);
}

Owner::Owner(const Passport &passport)
    : m_passport(passport)
{

}

/*
 * Getters / setters starts;
 */

Owner::Passport Owner::passport(void) const noexcept
{
    return m_passport;
}

/*
 * Getters / setters ends;
 */

std::string Owner::to_string(void) const
{
    return std::move(m_passport.to_string());
}

}   // !lab_6;
