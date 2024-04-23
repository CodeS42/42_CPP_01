#include "../headers/HumanB.hpp"

HumanB::HumanB(std::string name) 
{
    // std::cout << "Human B " << name << " has been created." << std::endl;
    this->name = name;
}

HumanB::~HumanB()
{
    // std::cout << "Human B " << name << " has been destroyed." << std::endl;
}

void HumanB::attack(void)
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
