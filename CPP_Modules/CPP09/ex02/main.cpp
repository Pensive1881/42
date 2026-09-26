#include "PmergeMe.hpp"

int main(int ac, char** av)
{
    try
    {
        PmergeMe sorter;

        sorter.process(ac, av);
    }
    catch (const std::exception& exception)
    {
        std::cerr << exception.what() << std::endl;
        return 1;
    }

    return 0;
}