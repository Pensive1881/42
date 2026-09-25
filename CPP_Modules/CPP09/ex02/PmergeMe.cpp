#include "PmergeMe.hpp"

#include <algorithm>
#include <climits>
#include <ctime>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>

PmergeMe::PmergeMe()
    : _vector(0),
      _dequeTime(0)
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _vector(other._vector),
      _deque(other._deque),
      _vectorTime(other._vectorTime),
      _dequeTime(other._dequeTime)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
        _vectorTime = other._vectorTime;
        _dequeTime = other._dequeTime;
    }

    return *this;
}

PmergeMe::~PmergeMe()
{
}

int PmergeMe::parse_number(
    const std::string& argument) const
{
    if (argument.empty())
        throw std::runtime_error("Error");
    
    for (std::size_t i = 0; i < argument.length(); ++i)
    {
        if (argument[i] < '0' || argument[i] > '9')
            throw std::runtime_error("Error");
    }

    std::istringstream input(argument);
    long number;

    input >> number;

    if (input.fail() || !input.eof() || number <= 0 || number > INT_MAX)
    {
        throw std::runtime_error("Error");
    }

    return static_cast<int>(number);
}

void PmergeMe::fillVector(int ac, char** av)
{
    _vector.clear();

    for (int i = 1; i < ac; ++i)
        _vector.push_back(parse_number(av[i]));
}

void PmergeMe::fillDeque(int ac, char **av)
{
    _deque.clear();

    for (int i = 1; i < ac; ++i)
        _deque.push_back(parse_number(av[i]));
}

void PmergeMe::fordJohnsonVector(std::vector<int>& sequence)
{
    if (sequence.size() <= 1)
        return;

    bool hasOdd = sequence.size() % 2 != 0;
    int oddValue = 0;

    if (hasOdd)
        oddValue = sequence.back();

    std::vector<std::pair<int, int> > pairs;

    for (std::size_t i = 0; i + 1 < sequence.size(); i += 2)
    {
        if (sequence[i] < sequence[i + 1])
        {
            pairs.push_back(
                std::make_pair(sequence[i], sequence[i + 1]));
        }
        else
        {
            pairs.push_back(
                std::make_pair(sequence[i + 1], sequence[i]));
        }
    }

    std::vector<int> maximums;

    for (std::size_t i = 0; i < pairs.size(); ++i)
        maximums.push_back(pairs[i].second);

    fordJohnsonVector(maximums);

    std::vector<std::pair<int, int> > orderPairs;
    std::vector<bool> used(pairs.size(), false);

    for (std::size_t i = 0; i < maximums.size(); ++i)
    {
        for (std::size_t j = 0; j < pairs.size(); ++i)
        {
            if (!used[j] && pairs[j].second == maximums[i])
            {
                orderedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    std::vector<int> chain;

    chain.push_back(orderedPairs[0].first);

    for (std::size_t i = 0; i < orderedPairs.size(); ++i)
        chain.push_back(orderedPairs[i].second);

    std::size_t previousJacobsthal = 1;
    std::size_t currentJacobsthal = 3;
    std::size_t previousInserted = 1;

    while (previousInserted < orderedPairs.size())
    {
        std::size_t upper = currentJacobsthal;

        if (upper > orderedPairs.size())
            upper = orderedPairs.size();

        for (std::size_t i = upper; i > previousInserted; --i)
        {
            std::size_t pairIndex = i - 1;
            int pendingValue = orderedPairs[pairIndex].first;
            int pairedMaximum = orderedPairs[pairIndex].second;

            std::vector<int>::iterator maximumPosition =
                std::lower_bound(
                    chain.begin(),
                    chain.end(),
                    pairedMaximum);

            std::vector<int>::iterator position =
                std::lower_bound(
                    chain.begin(),
                    maximumPosition + 1,
                    pendingValue);
            
            chain.insert(position, pendingValue);
        }

        previousInserted = upper;

        std::size_t nextJacobsthal = currentJacobsthal = nextJacobsthal;
        
        previousJacobsthal = currentJacobsthal;
        currentJacobsthal = nextJacobsthal;
    }

    if (hasOdd)
    {
        std::vector<int>::iterator position =
            std::lower_bound(
                chain.begin(),
                chain.end(),
                oddValue);

        chain.insert(position, oddValue);
    }

    sequence = chain;
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& sequence)
{
    if (sequence.size() <= 1)
        return;

    bool hasOdd = sequence.size() % 2 != 0;
    int oddValue = 0;

    if (hasOdd)
        oddValue = sequence.back();

    std::deque<std::pair<int, int> > pairs;

    for(std::size_t i = 0; i + 1 < sequence.size(); i += 2)
    {
        if (sequence[i] < sequence[i + 1])
        {
            pairs.push_back(
                std::make_pair(sequence[i], sequence[i + 1]));
        }
        else
        {
            pairs.push_back(
                std::make_pair(sequence[i + 1], sequence[i]));
        }
    }

    std::deque<int> maximums;

    for (std::size_t i = 0; i < pairs.size(); ++i)
        maximums.push_back(pairs[i].second);

    fordJohnsonDeque(maximums);

    std::deque<std::pair<int, int> > orderedPairs;
    std::deque<bool> used(pairs.size(), false);

    for (std::size_t i = 0; i < maximums.size(); ++i)
    {
        for (std::size_t j = 0; i < pairs.size(); ++j)
        {
            if (!used[j] && pairs[j].second == maximums[i])
            {
                orderedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    std::deque<int> chain;

    chain.push_back(orderedPairs[0].first);

    for (std::size_t i = 0; i < orderedPairs.size(); ++i)
        chain.push_back(orderedPairs[i].second);

    std::size_t previousJacobsthal = 1;
    std::size_t currentJacobsthal = 3;
    std::size_t previousInserted = 1;

    while (previousInserted < orderedPairs.size())
    {
        std::size_t upper = currentJacobsthal;

        if (upper > orderedPairs.size())
            upper = orderedPairs.size();

        for (std::size_t i = upper; i > previousInserted; --i)
        {
            std::size_t pairIndex = i - 1;
            int pendingValue = orderedPairs[pairIndex].first;
            int pairedMaximum = orderedPairs[pairIndex].second;

            std::deque<int>::iterator maximumPosition =
                std::lower_bound(
                    chain.begin(),
                    chain.end(),
                    pairedMaximum);

            std::deque<int>::iterator position =
                std::lower_bound(
                    chain.begin(),
                    maximumPosition + 1,
                    pendingValue);

            chain.insert(position, pendingValue);
        }

        previousInserted = upper;

        std::size_t nextJacobsthal =
            currentJacobsthal + 2 * previousJacobsthal;

        previousJacobsthal = currentJacobsthal;
        currentJacobsthal = nextJacobsthal;
    }

    if (hasOdd)
    {
        std::deque<int>::iterator position =
            std::lower_bound(
                chain.begin(),
                chain.end(),
                oddValue);
        
        chain.insert(position,oddValue);
    }

    sequence = chain;
}

void PmergeMe::displaySequence(
    const std::string& label,
    const std::vector<int>& sequence) const
{
    std::cout << label;

    for (std::size_t i = 0; i < sequence.size(); ++i)
        std::cout << " " << sequence[i];
    
    std::cout << std::endl;
}

void PmergeMe::process(int ac, char** av)
{
    if (ac < 2)
        throw std::runtime_error("Error");

    std::clock_t vectorStart = std::clock();

    fillVector(ac, av);

    std::clock_t vectorFillEnd = std::clock();

    displaySequence("Before:", _vector);

    std::clock_t vectorSortStart = std::clock();

    fordJohnsonVector(_vector);

    std::clock_t vectorEnd = std::clock();

    _vectorTime = 
        (static_cast<double>(vectorFillEnd - vectorStart)
        + static_cast<double>(vectorEnd - vectorSortStart))
        * 1000000.0 / CLOCKS_PER_SEC;

    std::clock_t dequeStart = std::clock();

    fillDeque(ac, av);
    fordJohnsonDeque(_deque);

    std::clock_t dequeEnd = std::clock();

    _dequeTime = 
        static_cast<double>(DequeEnd - dequeStart)
        * 1000000.0 / CLOCK_PER_SEC;

    displaySequence("After:", _vector);

    std::cout << "Time to process a range of "
              << _vector.size()
              << " elements with std::vector : "
              << _vectorTime << " us " << std::endl;

    std::cout << "Time to process a range of "
              << _deque.size()
              << " elements with std::deque : "
              << _dequeTime <<  " us " << std::endl;
}
