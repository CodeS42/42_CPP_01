#include "../headers/Zombie.hpp"

int main(void)
{
    int i = 0;
    Zombie *horde = zombieHorde(5, "Foo");
    
    while (i < 5)
        horde[i++].announce();
    delete[] horde;

    return (0);
}