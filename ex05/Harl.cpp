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

void Harl::complain(const std::string& level) {
    for (int i = 0; i < 4; ++i) {
        if (_pairs[i].name == level) {
            std::cout << "[ " << level << " ]" << std::endl;
            (this->*(_pairs[i].func))();
            std::cout << std::endl;
            return;
        }
    }
}

Harl::Harl() {
    _pairs[0].name = "DEBUG";
    _pairs[0].func = &Harl::_debug;
    _pairs[1].name = "INFO";
    _pairs[1].func = &Harl::_info;
    _pairs[2].name = "WARNING";
    _pairs[2].func = &Harl::_warning;
    _pairs[3].name = "ERROR";
    _pairs[3].func = &Harl::_error;
}

Harl::~Harl() {}
