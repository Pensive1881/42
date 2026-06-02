#include "PhoneBook.hpp"
#include <iostream>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    std::string input;
    PhoneBook pb;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, input))
            break;
        if (input == "EXIT")
            break;
        else if (input == "ADD")
            pb.addContact();
        else if (input == "SEARCH")
            pb.searchContact();
        else
        {
            if (!input.empty())
                std::cout << "Invalid command! Use ADD, SEARCH or EXIT."
                          << std::endl;
        }
    }
    return (0);
}
