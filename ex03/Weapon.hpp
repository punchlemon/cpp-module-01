#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <string>

class Weapon {
    public:
        Weapon(const std::string& type = "Notype");
        ~Weapon();
        void setType(const std::string& type);
        std::string getType() const;
    private:
        std::string _type;
};

#endif /* __Weapon_HPP__ */
