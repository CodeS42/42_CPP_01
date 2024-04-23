#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

# define DEBUG 73634535
# define INFO 2474255
# define WARNING 1195912711
# define ERROR 75125298

class Harl
{ 
    private:
        void (Harl::*ptr_functions[4])();
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

    public:
        Harl();
        ~Harl();
        void complain(std::string level);
        unsigned int hash_string(std::string level);  
};

#endif