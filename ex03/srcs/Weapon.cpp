#include "../headers/Weapon.hpp"

Weapon::Weapon(std::string type)
{
    // std::cout << "Weapon " << type << " has been created." << std::endl;
    this->type = type;
}

Weapon::~Weapon()
{
    // std::cout << "Weapon " << type << " has been destroyed." << std::endl;
}

const std::string &Weapon::getType(void)
{
    return type;
}

void Weapon::setType(std::string new_type)
{
    type = new_type;
}
