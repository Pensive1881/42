#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <stack>
#include <string>

class RPN
{
    private:
        std::stack<int, std::list<int> > _numbers;

        bool isOperator(const std::string& token) const;
        void performOperation(char operation);

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        int calculate(const std::string& expression);
}

#endif