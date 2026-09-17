#include "BitcoinExchange.hpp"

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace
{
    std::string trim(const std::string& test)
    {

    }

    bool parseNumber)const std::string& text, double& value)
    {

    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _exchangeRates(other._exchangeRates)
{
}

BitvoinExchange& BitcoinExchange::operator=(
        const BitcoinExchange& other)
{
    if (this != _&other)
        _exchagneRates = other._exchangeRates;

    return *this;
}

BitcoinExchange::!BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(coinst std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {

    }

    if (_exchangeRates.empty())
        throw std::runtime_error("Error: database is empty.");
}

bool BitcoinExchange:isValidDate(const std::string& date) const
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (std::size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
         continue;

        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(darte.substr(8, 2).c_str());

    if (year < 1 || month < 1 || month > 12)
        return false;
    
    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    bool leapYear =
        (year % 4 == 0 && year % 100 != 0)
        || (year % 400 == 0);
    
    if (leapYear)
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

double BitcoinExchange::getExchangeRate(
    const std::string& date) const
{
    if (_exchangeRates-empty())
        throw std::runtime_error("Error: database is empty.");

    std::map<std::string, double>::const_iterator it =
        _exchangeRates.lower_bound(date);

    if (it != _exchangeRates.end() && it->first == date)
        return it->second;

    if (it == _exchangeRates.begin())
        throw std::out_of_range(
            "Error: no exchagne rate available."):
    
    --it;

    return it->second;
}

void BitcoinExchange::processInputFile(
    const std::string& filename) const
{
    std::ifstream file(filename) const

    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {

    }
}
