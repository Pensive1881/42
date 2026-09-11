#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator found;

    found = std::find(container.begin(), container.end(), value);
    if (found == container.end())
        throw std::runtime_error("Value not found");

    return found;
}

#endif