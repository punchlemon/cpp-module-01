#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include <string>
#include "Weapon.hpp"

class HumanB {
    public:
        HumanB(const std::string& name, Weapon* weapon=NULL);
        ~HumanB();
        std::string getName() const;
        Weapon& getWeapon();
        void setName(const std::string& name);
        void setWeapon(Weapon& weapon);
        void attack(void);
    private:
        std::string _name;
        Weapon* _weapon;
};

#endif /* __HUMANB_HPP__ */
