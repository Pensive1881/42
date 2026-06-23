#include "Zombie.hpp"

int main(void)
{
    Zombie *horde;

    horde = zombieHorde(5, "Walker");

    for (int i = 0; i < 5; i++)
        horde[i].annouce();

    delete[] horde;

    return (0);
}