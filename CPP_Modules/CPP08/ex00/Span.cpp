#include "Span.hpp"

#include <algorithm>
#include <stdexcept>

Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _minSize = other._numbers;
    }
    return *this
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw std::out_of_range("Span is full");

    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers")

    std::vector<int> sortedNumbers(_numbers);
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    long long shortest = static_cast<long long>(sortedNumbers[1])
        - static_cast<long long>(sortedNumbers[0]);

    for (std::size_t i = 1; i < sortedNumbers.size(); ++i)
    [
        long long difference = stati_cast<long long>(sorted Numbers[i])
            - static_cast<long long>(sortedNumbers[i - 1]);

        if (difference < shortest)
            shortest = difference;
    ]

    return static_cast<unsigned int>(shortest);
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw 
    
    std::vector<int>::const_iterator minimum;
    std::vector<int>::const_iterator maximum;

    minimum = std::min_element(_numbers.begin(), _numbers.end());
    maximum = std::max_element(_numbers.begin(), _numbers.end());

    long long longest = static_cast<long long>(*maximum)
        - static_cast<long long>(*minimum)

    return static_cast<unsigned int>(longest);
}