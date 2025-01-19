#include <iostream>
#include <map>
#include "Harl.hpp"

void Harl::_debug() {
    std::cout
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << ' '
        << "I really do!" << std::endl;
}

void Harl::_info() {
    std::cout
        << "I cannot believe adding extra bacon costs more money." << ' '
        << "You didn’t put enough bacon in my burger!" << ' '
        << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning() {
    std::cout
        << "I think I deserve to have some extra bacon for free." << ' '
        << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error() {
    std::cout
        << "This is unacceptable!" << ' '
        << "I want to speak to the manager now." << std::endl;
}

void Harl::complain(const std::string& level) {
    std::map<std::string, void (Harl::*)()>::iterator it;
    if (!level.empty() && (it = _commands.find(level)) != _commands.end()) {
        std::cout << "[ " << level << " ]" << std::endl;
        (this->*(it->second))();
    } else {
        std::cout << "[ Probably complaining about insignificant problems ]";
    }
    std::cout << std::endl;
}

Harl::Harl() {
    _commands["DEBUG"] = &Harl::_debug;
    _commands["INFO"] = &Harl::_info;
    _commands["WARNING"] = &Harl::_warning;
    _commands["ERROR"] = &Harl::_error;
}

Harl::~Harl() {}
