#include <cctype>
#include <iostream>

int empty_av_check(char **av)
{
    int i = 1;

    while (av[i])
    {
        if (av[i][0] == '\0')
            i++;
        else
        return (0);
    }
    return (1);
}

int main(int ac, char **av)
{
    if (ac == 1 || empty_av_check(av))
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else
    {
        int i = 1;
        while (av[i])
        {
            int j = 0;
            while (av[i][j])
            {
                std::cout << (char)std::toupper(av[i][j]);
                j++;
            }
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}