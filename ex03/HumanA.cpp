#include <iostream>
#include "HumanA.hpp"

std::string HumanA::getName() const {
    return _name;
}

Weapon& HumanA::getWeapon() {
    return _weapon;
}

void HumanA::setName(const std::string& name) {
    _name = name;
}

void HumanA::attack(void) {
    std::cout
        << getName()
        << " attacks with their "
        << getWeapon().getType()
        << std::endl;
}

HumanA::HumanA(const std::string& name, Weapon& weapon)
    : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {
    std::cout
        << getName()
        << " died"
        << std::endl;
}
