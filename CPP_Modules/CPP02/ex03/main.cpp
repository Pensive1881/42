#include <iostream>
#include "Point.hpp"

int main(void)
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    Point inside(5.0f, 5.0f);
    Point outside(10.0f, 10.0f);
    Point edge(5.0f, 0.0f);
    Point vertex(0.0f, 0.0f);

    std::cout << "Inside : " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;
    std::cout << "Edge   : " << bsp(a, b, c, edge) << std::endl;
    std::cout << "Vertex : " << bsp(a, b, c, vertex) << std::endl;

    return (0);
}