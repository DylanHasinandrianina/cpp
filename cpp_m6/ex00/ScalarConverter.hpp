#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <limits> // for numeric_limits
#include <iomanip> // for setprecision
#include <cstdlib> // for atof atol

class ScalarConvert{

    private:
        ScalarConvert();
        ScalarConvert(const ScalarConvert& copy);
        ScalarConvert& operator=(const ScalarConvert& copy);
        ~ScalarConvert();
    public:
        static void convert(std::string literal);
};


#endif