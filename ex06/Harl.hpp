#ifndef __HARL_HPP__
#define __HARL_HPP__

#define NUM_OF_FUNCS 4
#include <string>

class Harl {
    public:
        Harl();
        ~Harl();
        int getHarlLevel(const std::string& level) const;
        void complain(const std::string& level) const;
    private:
        void _debug() const;
        void _info() const;
        void _warning() const;
        void _error() const;
        std::string _names[NUM_OF_FUNCS];
        void (Harl::*_funcs[NUM_OF_FUNCS])(void) const;
};

#endif /* __HARL_HPP__ */
