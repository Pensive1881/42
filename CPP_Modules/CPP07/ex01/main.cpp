#include <iostream>
#include <string>

#include "iter.hpp"

template <typename T>
void printValue(const T& value)
{
    std::cout << value <<std::endl;
}

void increment(int& value)
{
    value++;
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    const std::string words[] = {"Hello", "template", "world"}

    std::cout << "Numbers:" <<std::endl;
    iter(numbers, 5, printValue<int>);

    iter(numbers, 5, increment);

    std::cout << "Incremented numbers:" << std::endl;
    iter(numbers, 5, printValue<int>);

    std::cout << "Words:" << std::endl;
    iter(words, 3, printValue<std::string>);

    return 0;
}