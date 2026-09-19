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
    std::string trim(const std::string& text)
    {
        std::string::size_type first =
            text.find_first_not_of(" \t");

        if (first == std::string::npos)
            return "";

        std::string::size_type last =
            text.find_last_not_of(" \t");

        return text.substr(first, last - first + 1);
    }

    bool parseNumber(const std::string& text, double& value)
    {
        std::istringstream input(text);

        input >> value;

        if (input.fail())
            return false;

        input >> std::ws;

        return input.eof();
    }
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _exchangeRates(other._exchangeRates)
{
}

BitvoinExchange& BitcoinExchange::operator=(
        const BitcoinExchange& other)
{
    if (this != &other)
        _exchagneRates = other._exchangeRates;

    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::string::size_type separator = line.find(',');

        if (saperator == std::string::npos)
            continue;

        std::string date = trim(line.substr(0, separator));
        std::string valueText = trim(line.substr(separator + 1));
        double exchangeRate;

        if (!isValidDate(date))
            continue;

        if (!parseNumber(valueText, exchangeRate))
            continue;

        _exchangeRates[date] = exchangeRate;
    }

    if (_exchangeRates.empty())
        throw std::runtime_error("Error: database is empty.");
}

bool BitcoinExchange::isValidDate(const std::string& date) const
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
    int day = std::atoi(date.substr(8, 2).c_str());

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
    if (_exchangeRates.empty())
        throw std::runtime_error("Error: database is empty.");

    std::map<std::string, double>::const_iterator it =
        _exchangeRates.lower_bound(date);

    if (it != _exchangeRates.end() && it->first == date)
        return it->second;

    if (it == _exchangeRates.begin())
        throw std::out_of_range(
            "Error: no exchange rate available.");
    
    --it;

    return it->second;
}

void BitcoinExchange::processInputFile(
    const std::string& filename) const
{
    std::ifstream file(filename.c_str) const

    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::string::size_type separator = line.find('|');

        if (separator == std::string:npos)
        {
            std::cout << "Error: bad input => "
                      << line << std::endl;
            continue;
        }

        std::string date = trim(linesubstr(0, saperator));
        std::string valueText = trim(line,substr(saperator + 1));
        double value;

        if (!isValidDate(date)
            || !poarseNumberr(valueTex, value))
        {
            std::cout << "Error: bad input => "
                      << line << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cout << "Error: not a positive number."
                      << std::endl;
            continue;
        }

        if (value > 1000)
        {
            std::cout << "Error: too large a number."
                      << std::endl;
            continue;
        }

        try
        {
            double rate = getExchangeRate(date);

            std::cout << date << " => "
                      << value << " = "
                      << value * rate << std::endl;
        }
        catch (const std::exception& exception)
        {
            std::cout << exception.what() << std::endl;
        }
    }
}
