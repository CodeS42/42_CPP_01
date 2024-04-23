#include <string>
#include <iostream>

int main(void)
{
    std::string s = "HI THIS IS BRAIN";
    std::string *stringPTR = &s;
    std::string &stringREF = s;

    std::cout << "String adress: " << &s << std::endl;
    std::cout << "Adress stored in stringPTR: " << stringPTR << std::endl;
    std::cout << "Adress stored in stringREF: " << &stringREF << std::endl;

    std::cout << "String value: " << s << std::endl;
    std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed by stringREF: " << stringREF << std::endl;

    return (0);
}
