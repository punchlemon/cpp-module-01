#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <string>

class Zombie {
    public:
        Zombie(const std::string& name="Noname");
        ~Zombie();
        void setName(const std::string& name);
        const std::string& getName() const;
        void announce() const;
    private:
        std::string _name;
};

Zombie *zombieHorde(int n, const std::string& name);

#endif /* __ZOMBIE_HPP__ */
