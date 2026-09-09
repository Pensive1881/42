#ifndef INTER_HPP
#define INTER_HPP

#include <cstddef>

template <typename T>
void inter(T* array, std::size_t length, void (*function)(T&))
{
    for (std::size_t index = 0; index < length; index++)
        function(array[index]);
}

template <typename T>
void inter(const T* array, std::size_t length, void (*function)(const T&))
{
    for (std::size_t index = 0; index < length; index++)
        function(array[index]);
}

#endif