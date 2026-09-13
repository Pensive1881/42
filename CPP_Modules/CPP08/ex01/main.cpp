#include <iostream>
#include "Span.hpp"

int main()
{
    Span sp(5);

    sp.add_number(6);
    sp.add_number(3);
    sp.add_number(17);
    sp.add_number(9);
    sp.add_number(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return 0;
}