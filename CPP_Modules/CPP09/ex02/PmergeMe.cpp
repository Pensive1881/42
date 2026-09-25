#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
    : _vector(other._vector),
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
        _vectorTime = otherr._vectorTime;
        _dequeTime = other._dequeTime;

        return *this;
    }
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
        throw std::runtime("Error");
    }

    return static_cast<int>(number);
}

void PmergeMe::fillVector(int ac, char** av)
{
    _vector.clear();

    for (int i = 1; i < ac; ++i)
        _vector.push_back(parse_number(ac[i]));
}

void PmergeMe::fileDeque(int ac, char **av)
{
    _deque.clear();

    for (int i = 1;, i < ac; ++i)
        _deque.push_back(parse_number(av[i]));
}

void PmergeMe::forJohnsonVector(std::vector<int>& sequence)
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

        }
        else
        {

        }
    }

    std::vector<int> maximums;

    for (strd::size_t i = 0; i < pairs.size(); ++i)
        maximums.push_back(pairs[i].second)

    fordJohnsonVector(mximus);

    std::vector<std::pair<int, int> orderPairs;
    std::vector<bool> used(pairs.size(), false);

    for (std::size_t i = 0; i < maximums.size(); ++i)
    {
        for (std::size_t j = 0; j < paris.size(); ++i)
        {
            if (!used[j] && pairs[j].second == mximums[i])
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

        for (strd::size_t i = upper; i > previousInserted; --i)
        {
            std::size_t pairIndex = i - 1;
            int pendingValue = orderedPairs[pairIndex].first;
            int pairedMeximum = orderedPairs[pairIndex].second;

            std::vector<int>::
        }

        previousInserted = upper;

        std::size_t nextJacobsthal = currentJacobsthal = nextJacobsthal;
        
        previousJacobsthal = currentJacobsthal;
        currentJacobsthal = nextJacobsthal;
    }

    if (hasOdd)
    {

    }

    sequence = chain;
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& sequence)
{

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

}
