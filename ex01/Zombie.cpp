#include <iostream>
#include <sstream>
#include "Zombie.hpp"

std::string Zombie::getName() const {
    return _name;
}

void announceMessage(const std::string& name, const std::string& sentence) {
    std::cout << name << ": " << sentence << std::endl;
}

void Zombie::setName(std::string name) {
    _name = name;
}

void Zombie::announce() const {
    announceMessage(getName(), "BraiiiiiiinnnzzzZ...");
}

Zombie::Zombie( std::string name) {
    _name = name;
}

Zombie::~Zombie() {
    announceMessage(getName(), "Ughhhhh...");
}
