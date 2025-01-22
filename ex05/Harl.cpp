#include <iostream>
#include "Harl.hpp"

void Harl::_debug() {
    std::cout
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl
        << "I really do!" << std::endl;
}

void Harl::_info() {
    std::cout
        << "I cannot believe adding extra bacon costs more money." << std::endl
        << "You didn’t put enough bacon in my burger!" << std::endl
        << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning() {
    std::cout
        << "I think I deserve to have some extra bacon for free." << std::endl
        << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error() {
    std::cout
        << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

int Harl::getHarlLevel(const std::string& level) {
    for (int i = 0; i < NUM_OF_FUNCS; ++i) {
        if (_names[i] == level) {
            return i;
        }
    }
    return -1;
}

void Harl::complain(const std::string& level) {
    int id = getHarlLevel(level);
    if (id != -1) {
        std::cout << "[ " << level << " ]" << std::endl;
        (this->*(_funcs[id]))();
        std::cout << std::endl;
    }
}

Harl::Harl() {
    _names[0] = "DEBUG";
    _names[1] = "INFO";
    _names[2] = "WARNING";
    _names[3] = "ERROR";
    _funcs[0] = &Harl::_debug;
    _funcs[1] = &Harl::_info;
    _funcs[2] = &Harl::_warning;
    _funcs[3] = &Harl::_error;
}

Harl::~Harl() {}
