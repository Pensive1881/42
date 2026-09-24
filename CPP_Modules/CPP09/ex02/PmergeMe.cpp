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
