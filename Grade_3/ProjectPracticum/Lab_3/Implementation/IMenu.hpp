/************************************
 * Laboratory work #3;              *
 * Student Bukhta Mykyta;           *
 * Grade: 3;                        *
 * Group Software Engineering 3.04; *
 ************************************
 */

#ifndef BUKHTAMYKYTA_LAB3_IMENU_HPP
#define BUKHTAMYKYTA_LAB3_IMENU_HPP

#include <inttypes.h>

namespace lab_3 {

class IMenu {
public: 
    virtual void draw(void) = 0;
};

}   // !lab_3;

#endif  // !BUKHTAMYKYTA_LAB3_IMENU_HPP;