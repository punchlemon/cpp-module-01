#include <iostream>
#include "Zombie.hpp"

const std::string& Zombie::getName() const {
    return _name;
}

void announceMessage(const std::string& name, const std::string& sentence) {
    std::cout
        << name
        << ": "
        << sentence
        << std::endl;
}

void Zombie::announce() const {
    announceMessage(getName(), "BraiiiiiiinnnzzzZ...");
}

Zombie::Zombie(const std::string& name) : _name(name) {}

Zombie::~Zombie() {
    announceMessage(getName(), "Ughhhhh...");
}
