// Exercise 1.1 resolution in C++
#include <iostream>
#include <string>

int main() {
    int age;
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cout << "Your name is " << name << " and you are " << age << " years old." << std::endl;
    system("pause");
    return 0;
}