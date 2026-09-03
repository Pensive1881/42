#include "ScalarConverter.hpp"

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

namespace
{
    bool isSpecialValue(double value)
    {
        
    }

    bool parseLiteral(Const std::string& literal, double& value)
    {

    }
    
    void printChar(double value)
    {

    }

    void printInt(double value)
    {

    }

    void printFloat(double value)
    {

    }

    void printDouble(double value)
    {

    }
}

void ScalarConverter::convert(const std::string& literal)
{
    double value;

    if (!parseLiteral(literal, value))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "flat: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}