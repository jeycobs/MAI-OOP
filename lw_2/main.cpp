#include <ios>
#include <iostream>
#include "include/Octal.hpp"

int main() {
    Octal obj("77777"),obj2("123");
    std::cout << obj << " " << obj2 <<  std::endl;
    std::cout << std::boolalpha << (obj == Octal("77777")) << std::endl;
    std::cout << std::boolalpha << (Octal("55555") < obj) << std::endl;
    std::cout << std::boolalpha << (Octal("55555") > Octal("44444")) << std::endl;
    std::cout << std::boolalpha << (obj2 != Octal("133")) << std::endl;
    return 0;
}