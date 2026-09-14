#include "Span.hpp"

#include <algorithm>
#include <climits>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int maxSize)
    : _maxSize(maxSize)
{
}

Span::Span(const Span& other)
    : _maxSize(other._maxSize),
      _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }

    return *this;
}

Span::~Span()
{
}

void    Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw std::out_of_range("Span is full");

    _numbers.push_back(number);
}

unsigned int    Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to calculate a span");
    
    std::vector<int> sortedNumbers(_numbers);
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    unsigned int shortest = UINT_MAX;

    for (std::size_t i = 1; i < sortedNumbers.size(); ++i)
    {
        unsigned int difference =
            static_cast<unsigned int>(sortedNumbers[i])
            - static_cast<unsigned int>(sortedNumbers[i - 1]);
        
        if (difference < shortest)
            shortest = difference;
    }

    return shortest;
}

unsigned int    Span::longestSpan() const
{
    if ()
        throw std::logic_error("");
    
    std::vector<int>::const_iterator minimum =
        std::min_element(_numbers.begin(), _numberes.end());

    std::vector<int>::const_iterator maximum = 
        std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int>(*maximum)
         - static_cast<unsigned int>(*minimum);
}