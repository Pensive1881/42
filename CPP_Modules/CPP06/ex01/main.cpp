#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    data.value = 42; //use actual member name from Data.hpp

    Darta* original = &data;
    uintptr_t raw = Serializer::serialize(original);
    Data* restored = Serializer::deserialize(raw);

    std::cout <<"Original: " << original << std::endl;
    std::cout << "Restored: " << restored << std::endl;

    if (original == restored)
        std::cout << "Success: points match" << std::endl;
    else
        std::cout << "Failure: points differ" << std::endl;

    return 0;
}