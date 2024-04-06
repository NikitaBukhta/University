/************************************
 * Laboratory work #6;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *                       *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB_6_CONFIG_HPP
#define BUKHTAMYKYTA_LAB_6_CONFIG_HPP

#include <inttypes.h>
#include <string>
#include <cmath>

namespace lab_6 {
namespace config {

const uint8_t FLOATING_NUMBERS_COUNT = 2;
const uint8_t NUMBER_CONVERTOR_DEVIDER = std::pow(10, FLOATING_NUMBERS_COUNT);
const uint8_t FULL_PERCENT = 100;
const char FLOATING_DELIMITER = '.';
const char DATA_DELIMITER = ' ';
const std::string DATA_DELIMITER_STRING = " ";

}   // !config;
}   // !lab_6

#endif  // !BUKHTAMYKYTA_LAB_6_CONFIG_HPP;