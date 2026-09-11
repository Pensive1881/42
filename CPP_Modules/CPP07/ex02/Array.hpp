#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
    private:
        T*              _data;
        unsigned int    _size;

    public:
        Array() : _data(NULL), _size(0)
        {
        }

        Array(unsigned int size) : _data(new T[size]), _size(size)
        {
        }

        Array(const Array& other) : _data(NULL), _size(0)
        {
            *this = other;
        }
        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                T* copy = NULL;

                if (other._size > 0)
                {
                    copy = new T[other._size];
                    for (unsigned int i = 0; i <other._size; i++)
                        copy[i] = other._data[i];
                }

                delete[] _data;
                _data = copy;
                _size = other._size;
            }
            return *this;
        }

        ~Array()
        {
            delete[] _data;
        }

        T& operator[](unsigned int index)
        {
            if (index >= _size)
                throw IndexOutOfBoundsException();
            return _data[index];
        }

        const T& operator[](unsigned int index) const
        {
            if (index >= _size)
                throw IndexOutOfBoundsException();
            return _data[index];
        }

        unsigned int size() const
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