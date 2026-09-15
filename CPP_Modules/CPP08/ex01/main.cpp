#include "Span.hpp"

#include <exception>
#include <iostream>
#include <vector>

int main()
{
    std::cout << "Subject test:" << std::endl;

    try
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: "
                  << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  "
                  << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& exception)
    {
        std::cout << "Exception: "
                  << exception.what() << std::endl;
    }

    std::cout << "\nFull Span test: " << std::endl;

    try
    {
        Span sp(2);

        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);
    }
    catch (const std::exception& exception)
    {
        std::cout << "Exception: "
                  << exception.what() << std::endl;
    }

    std::cout << "\nNot enough numbers test: " << std::endl;

    try
    {
        Span sp(1);

        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (const std::exception& exception)
    {
        std::cout << "Exception: "
                  << exception.what() << std::endl;
    }

    std::cout << "\nLarge range test:" << std::endl;

    try
    {
        const unsigned int size = 10000;
        std::vector<int> numbers;

        for (unsigned int i = 0; i < size; ++i)
        {
            numbers.push_back(static_cast<int>(i));
        }

        Span largeSpan(size);
        largeSpan.addNumber(numbers.begin(), numbers.end());

        std::cout << "Shortest span: "
                  << largeSpan.shortestSpan() << std::endl;
        std::cout << "Largest span:  "
                  << largeSpan.longestSpan() << std::endl;
    }
    catch (const std::exception& exception)
    {
        std::cout << "Exception: "
                  << exception.what() << std::endl;
    }

    return 0;
}