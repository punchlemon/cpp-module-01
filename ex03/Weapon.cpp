#include <iostream>
#include "Weapon.hpp"

std::string Weapon::getType() const {
    return _type;
}

void Weapon::setType(const std::string& type) {
    _type = type;
}

Weapon::Weapon(const std::string& type) : _type(type) {}

Weapon::~Weapon() {
    std::cout
        << getType()
        << " is broken"
        << std::endl;
}
