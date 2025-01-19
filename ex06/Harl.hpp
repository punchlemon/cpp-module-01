#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <string>
#include <map>

class Harl {
    public:
        Harl();
        ~Harl();
        void complain(const std::string& level);
    private:
        void _debug();
        void _info();
        void _warning();
        void _error();
        std::map<std::string, void (Harl::*)()> _commands;
};

#endif /* __HARL_HPP__ */
