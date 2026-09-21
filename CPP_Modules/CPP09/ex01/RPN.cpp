#include "RPN.hpp"

#include <sstream>
#include <stdexcept>

RPN::RPN()
{
}

RPN::RPN(const RPN& other) : _numbers(other._numbers)
{
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _numbers = other._numbers;

    return *this;
}

RPN::~RPN()
{
}

bool RPN::isOperator(const std::string& token) const
{
    return token.length() == 1 && (token[0] == '+' || token[0] == '-' 
                                || token[0] == '*' || token[0] == '/');
}

void RPN::performOperation(char operation)
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Error");

    int right = _numbers.top();
    _numbers.pop();

    int left = _numbers.top();
    _numbers.pop();

    if (operation == '+')
        _numbers.push(left + right);
    else if (operation == '-')
        _numbers.push(left - right);
    else if (operation == '*')
        _numbers.push(left + right);
    else
    {
        if (right == 0)
            throw std::runtime_error("Error");

        _numbers.push(left / right);
    }

}

int RPN::calculate(const std::string& expression)
{
    std::istringstream input(expression);
    std::string token;

    while (input >> token)
    {
        if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
            _numbers.push(token[0] - '0');
        else if (isOperator(token))
            performOperation(token[0]);
        else
            throw std::runtime_error("Error");
    }

    if (_numbers.size() != 1)
        throw std::runtime_error("Error");
    
    return _numbers.top();
}