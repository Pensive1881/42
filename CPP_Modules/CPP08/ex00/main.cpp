#include <iostream>
#include <vvector>
#include <exception>

#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    nubmers.push_back(30);
    numbers.push_back(40);

    try
    {
        std::vector<int>::iterator found = easyfind(numbers, 30);
        std::cout << "Found: " << *foud <<std::endl;
    }
    catch (const std::exception& error)
    {
        std::cout <<"Error: " << error.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator found = easyfind(numbers, 99);
        std::cout << "Found: " << *found << std::endl;
    }
    catch(const std::exception&error)
    {
        std::cout << "Error: " << error.what() << std::endl;
    }

    return 0
}