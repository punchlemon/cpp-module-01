#include <iostream>
#include "HumanB.hpp"

std::string HumanB::getName() const {
    return _name;
}

Weapon& HumanB::getWeapon() {
    return *_weapon;
}

void HumanB::setName(const std::string& name) {
    _name = name;
}

void HumanB::setWeapon(Weapon& weapon) {
    _weapon = &weapon;
}

void HumanB::attack(void) {
    std::cout
        << getName()
        << " attacks with their "
        << getWeapon().getType()
        << std::endl;
}

HumanB::HumanB(const std::string& name, Weapon* weapon)
    : _name(name), _weapon(weapon) {}

HumanB::~HumanB() {
    std::cout
        << getName()
        << " died"
        << std::endl;
}
