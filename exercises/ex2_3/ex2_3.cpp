#include <iostream>
#include <fstream>
#include <string>

typedef struct student {
    std::string name;
    int age{};
    int id{};
} student;

int main() {
    std::ofstream ofs{"../students.txt"};
    if (!ofs.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        exit(1);
    }
    student students[3];
    for (auto &s: students) {
        std::cout << "Enter your name: ";
        std::getline(std::cin, s.name);
        std::cout << "Enter your age: ";
        std::cin >> s.age;
        std::cout << "Enter your id: ";
        std::cin >> s.id;
        std::cin.ignore();
    }
    for (auto &s: students) {
        ofs << s.name << ';'
            << s.age << ';'
            << s.id << std::endl;
    }
    return 0;
}