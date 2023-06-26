#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream ifs{"../students.txt"};
    if (!ifs.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        exit(1);
    }
    while (!ifs.eof()) {
        std::string name;
        int age, id;
        char delim = ';';
        std::getline(ifs, name, delim);
        ifs >> age >> delim >> id >> std::ws;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Id: " << id << std::endl;
    }
    return 0;
}
