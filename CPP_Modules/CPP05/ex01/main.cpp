#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat worker("Worker", 100);
        Form contract("Contract", 50, 25);

        std::cout << contract << std::endl;

        worker.signForm(contract);
        std::cout << contract << std::endl;

        boss.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (const std::exception& exception)
    {
        std::cout << "Exception: " 
                  << exception.what() << std::endl;
    }

    try
    {
        Form invalid("Invalid", 0, 151);
        std::cout << invalid << std::endl;
    }
    catch (const std::exception& exception)
    {
        std::cout << "Exception: "
                  << exception.what() << std::endl;
    }

    return 0;
}