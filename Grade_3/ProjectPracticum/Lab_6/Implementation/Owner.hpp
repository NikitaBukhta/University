/************************************
 * Laboratory work #6;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *                       *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB_6_OWNER_HPP
#define BUKHTAMYKYTA_LAB_6_OWNER_HPP

#include <string>

namespace lab_6 {

class Owner {
public:
    struct FullName {
        std::string first_name;
        std::string second_name;
        std::string middle_name;

        FullName(void) = default;
        FullName(std::string init_first_name, std::string init_second_name, std::string init_middle_name = "");
        bool operator== (const FullName &other) const;
        bool operator!= (const FullName &other) const;
        std::string to_string(void) const;
    };

    struct Passport {
        std::string series;
        std::string number;
        FullName full_name;

        Passport(void) = default;
        Passport(FullName init_full_name, std::string init_series, std::string init_number);
        bool operator== (const Passport &other) const;
        bool operator!= (const Passport &other) const;

        std::string to_string(void) const;
    };

public:
    Owner(void) = default;
    Owner(const Passport &passport);
    virtual ~Owner() = default;

    /*
     * Getters / setters starts;
     */

    Passport passport(void) const noexcept;

    /*
     * Getters / setters ends;
     */

    /*
     * Class interface starts;
     */

    std::string to_string(void) const;

    /*
     * Class interface ends;
     */

private:
    Passport m_passport;
};

}   // !lab_6;

#endif  // !BUKHTAMYKYTA_LAB_6_OWNER_HPP;