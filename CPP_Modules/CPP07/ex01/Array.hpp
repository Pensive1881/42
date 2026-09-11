#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
    private:
        T*              _date;
        unsigned int    _size;

    public:
        Array() : _data(NULL), _size(0)
        {
        }

        Array(unsigned int size) : _data(new T[size]), size(size)
        {
        }

        Array(const Array& other) : _data(NULL), _size(0)
        {
            *this = other;
        }
        Array& operator=(const Array& other)
        [

        ]

        ~Array()
        {
            delete[] _data;
        }

        T& operator[](unsigned int index)
        {

        }

        const T& operator[](unsigned int index) const
        {

        }

        unsigned in size() const
        {
            return _size;
        }

        class IndexOutOfBoundsException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Array index is out of bounds";
                }
        };
};

#endif