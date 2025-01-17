#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <string>

class Zombie {
    public:
        Zombie(const std::string& name);
        ~Zombie();
        const std::string& getName() const;
        void announce() const;
    private:
        std::string _name;
};

void randomChump(const std::string& name);

#endif /* __ZOMBIE_HPP__ */
