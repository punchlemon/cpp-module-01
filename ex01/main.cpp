#include "Zombie.hpp"

int main( void ) {
    int max = 2;
    Zombie *horde = zombieHorde(max, "Joe");
    for (int i = 0; i < max; i++) {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}
