#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Valid bureaucrat ===" << std::endl;

    try
    {
        bureaucrat bob("Bob", 2);

        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;

        bob.incrementGrade();
    }
    catch (const std::exception& exception)
    {
        std::cout << "Exception: " << exception.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== Grade too high ===" << std::endl;

    try
    {
        Bureaucrat invalid("TooHigh", 0);
        std::cout << invalid << std::endl;
    }
    catch (const std::exception& exception)
    {
        std::cout << "Exception: " << exception.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "== Grade too low ===" << std::endl;

    try
    {
        Bureaucrat invalid("TooLow", 151);
        std::cout << invalid << std::endl;
    }
    catch (const std::exception& exception)
    {
        std::cout << "Exception: " << exception.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "" << std::endl;

    try
    {
        Bureaucrat alice("Alice", 149);

        std::cout << alice << std::endl;

        alice.decrementGrade();
        std::cout << alice << std::endl;

        alice.decrementGrade();
    }
    catch (const std::exception& exception)
    {
        std::cout << "Exception: " << exception.what() << std::endl;
    }

    return 0;
}