#include "BitcoinExchange.hpp"

#include <exception>
#include <iostream>

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file."
                  << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange exchange;

        exchange.loadDatabase("data.csv");
        exchange.processInputFile(av[1]);
    }
    catch (const std::exception& exception)
    {
        std::cout << exception.what() << std::endl;
        return 1;
    }

    return 0;
}