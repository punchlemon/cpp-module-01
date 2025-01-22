#ifndef __HARL_HPP__
#define __HARL_HPP__

#define NUM_OF_FUNCS 4
#include <string>

class Harl {
    public:
        Harl();
        ~Harl();
        int getHarlLevel(const std::string& level);
        void complain(const std::string& level);
    private:
        void _debug();
        void _info();
        void _warning();
        void _error();
        std::string _names[NUM_OF_FUNCS];
        void (Harl::*_funcs[NUM_OF_FUNCS])(void);
};

#endif /* __HARL_HPP__ */
