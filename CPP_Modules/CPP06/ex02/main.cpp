#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{

}

void identify(Base* p)
{

}

void identify(Base& p)
{

}

int main()
{
    std::srand(std::time(NULL));

    Base* instance = generater();

    identify(instance);
    identify(*instance);
    delete instance;
    return 0;
}