#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    data.number = 42; //use actual member name from Data.hpp

    Data* original = &data;
    uintptr_t raw = Serializer::serialize(original);
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original: " << original << std::endl;
    std::cout << "Restored: " << restored << std::endl;

    if (original == restored)
        std::cout << "Success: pointers match" << std::endl;
    else
        std::cout << "Failure: pointers differ" << std::endl;

    return 0;
}