#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

#include <string>
#include "Weapon.hpp"

class HumanA {
    public:
        HumanA(const std::string& name, Weapon& weapon);
        ~HumanA();
        void setName(const std::string& name);
        void attack(void);
        std::string getName() const;
        Weapon& getWeapon();
    private:
        std::string _name;
        Weapon& _weapon;
};

#endif /* __HUMANA_HPP__ */
