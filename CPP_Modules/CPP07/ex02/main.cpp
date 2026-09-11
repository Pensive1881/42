#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

#include "Array.hpp"

#define MAX_VAL 750

int main()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    std::srand(std::time(NULL));

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    {
        Array<int> copy = numbers;
        Array<int> secondCopy(copy);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "Deep copy failed." << std::endl;
            delete[] mirror;
            return 1;
        }
    }

    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what() << std::endl;
    }

    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& error)
    {
        std::cerr << error.what() << std::endl;
    }

    delete[] mirror;
    return 0;
}