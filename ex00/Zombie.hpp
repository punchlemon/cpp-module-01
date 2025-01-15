#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <string>

class Zombie {
    public:
        Zombie( std::string name);
        ~Zombie();
        void announce() const;
        std::string getName() const;
    private:
        std::string _name;
};

void randomChump( std::string name );

#endif /* __ZOMBIE_HPP__ */
