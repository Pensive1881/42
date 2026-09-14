#ifndef SPAN_HPP
#define SPAN_HPP

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
            std::vector<int> newNumbers(first, last);

            std::size_t available =
                static_cast<std::size_t>(_maxSize) - _numberrs.size();
            
            if (newNumbers.size() > available)
                throw std::out_of_range("Span is full");

            _numbers.insert(_numbers.end(),
                            newNumbers.begin(),
                            newNumbers.end());
        }

        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};

#endif