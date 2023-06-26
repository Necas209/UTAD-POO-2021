#include <iostream>
#include <fstream>
#include <string>


struct student {
    std::string name;
    int age{};
    int id{};
};
typedef student Student;

int main() {
    std::ofstream ofs{"../students.txt"};
    if (!ofs.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        exit(1);
    }
    Student students[3];
    for (auto &student: students) {
        std::cout << "Enter your name: ";
        std::getline(std::cin, student.name);
        std::cout << "Enter your age: ";
        std::cin >> student.age;
        std::cout << "Enter your id: ";
        std::cin >> student.id;
        std::cin.ignore();
    }
    for (auto &student: students) {
        ofs << student.name << ';';
        ofs << student.age << ';';
        ofs << student.id << std::endl;
    }
    return 0;
}