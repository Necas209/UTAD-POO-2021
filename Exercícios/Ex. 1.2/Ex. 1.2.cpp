#include <iostream>
#include <string>

int main() {
    int i;
    float f;
    char c;
    std::string s;
    std::cout << "Enter an integer: ";
    std::cin >> i;
    std::cout << "Enter a floating point number: ";
    std::cin >> f;
    std::cout << "Enter a character: ";
    std::cin >> c;
    std::cin.ignore();
    std::cout << "Enter a string: ";
    getline(std::cin, s);
    std::cout << "Integer entered: " << i << std::endl;
    std::cout << "Float entered: " << f << std::endl;
    std::cout << "Character entered: " << c << std::endl;
    std::cout << "String entered: " << s << std::endl;
    return 0;
}