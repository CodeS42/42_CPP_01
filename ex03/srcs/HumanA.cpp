#include "../headers/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
    // std::cout << "Human A " << name << " has been created." << std::endl;
    this->name = name;
    this->weapon = &weapon;
}

HumanA::~HumanA()
{
    // std::cout << "Human A " << name << " has been destroyed." << std::endl;
}

void HumanA::attack(void)
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
