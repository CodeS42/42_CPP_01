#include "../headers/Harl.hpp"

Harl::Harl()
{
    // std::cout << "Harl has been created." << std::endl;
    ptr_functions[0] = &Harl::debug;
    ptr_functions[1] = &Harl::info;
    ptr_functions[2] = &Harl::warning;
    ptr_functions[3] = &Harl::error;   
}

Harl::~Harl()
{
    // std::cout << "Harl has been destroyed." << std::endl;
}

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

unsigned int Harl::hash_string(std::string level)
{
    unsigned int hash = 0;
    int i = 0;
    while (level[i])
        hash += hash * 31 + level[i++];

    return hash;
}

void    Harl::complain(std::string level)
{
    unsigned int lvl = hash_string(level);
    int i = -1;

    switch (lvl)
    {
        case DEBUG:
            i = 0;
            break;
        case INFO:
            i = 1;
            break;
        case WARNING:
            i = 2;
            break;
        case ERROR:
            i = 3;
            break;
        default :
            std::cout << "Invalid complaint level." << std::endl;
    }
    if (i >= 0 && i <= 3)
        (this->*ptr_functions[i])();
}
