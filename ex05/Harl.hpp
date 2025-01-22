#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <string>

class Harl;

struct stringFunctionPair {
    std::string name;
    void (Harl::*func)(void);
};

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
        stringFunctionPair _pairs[4];
};

#endif /* __HARL_HPP__ */
