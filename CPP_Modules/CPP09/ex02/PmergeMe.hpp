#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        double _vectorTime;
        double _dequeTime;

        int parse_number(const std::string& argument) const;

        void fillVector(int ac, char** av);
        void fillDeque(int ac, char** av);

        void fordJohnsonVector(std::vector<int>& sequence);
        void fordJohnsonVector(std::deque<int>& sequence);

        void displaySequence(
            const std::string& label,
            const std::vector<int>& sequence) const;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void process(int ac, char** av);
};

#endif