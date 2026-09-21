#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& other) : _numbers(other._numbers)
{
}

RPN& RPN::operator=(constRPN& OTHER)
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
    return ;
}

void RPN::performOperation(char operation)
{

}

int RPN::calculate(const std::string& expression)
{

}