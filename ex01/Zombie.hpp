#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <string>

class Zombie {
    public:
        Zombie(std::string name = "Noname");
        ~Zombie();
        void announce() const;
        std::string getName() const;
        void setName(std::string name);
    private:
        std::string _name;
};

Zombie *zombieHorde(int n, std::string name);

#endif /* __ZOMBIE_HPP__ */
