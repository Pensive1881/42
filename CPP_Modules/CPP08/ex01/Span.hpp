#ifndef SPAN_HPP
#define SPAN_HPP

#include <iterator>
#include <stdexcept>
#include <vector>

class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;

    public: 
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);

        template <typename InputIterator>
        void addNumber(InputIterator first, InputIterator last)
        {
            std::size_t count = std::distance(first, last);

            if (_numbers.size() + count > _maxSize)
                throw std::out_of_range("Span is full");

            _numbers.insert(_numbers.end(), first, last);
        }

        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};

#endif