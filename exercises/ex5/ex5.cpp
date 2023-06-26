#include "employee.h"
#include <algorithm>
#include <array>
#include <chrono>
#include <clocale>
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 5.4
    employee employee1{
            "Joca Gaio",
            std::chrono::year{1987} / std::chrono::September / 20,
            "Rua da direita n 2",
            25023, "Pintura"
    };
    employee employee2{
            "Ana Rola",
            std::chrono::year{1990} / std::chrono::February / 4,
            "Rua da esquerda n 3",
            25024, "Comercial"
    };
    setlocale(LC_ALL, "");
    // 5.5
    std::cout << "Worker 1:" << std::endl;
    employee1.print();
    std::cout << "Worker 2:" << std::endl;
    employee2.print();
    // 5.6
    employee1.set_address("Rua do meio n 4");
    employee1.set_sector("Ferragem");
    // 5.7
    date birth_date = employee2.get_birth_date();
    employee2.set_birth_date({birth_date.year() / birth_date.month() / 5});
    // 5.9
    employee employee3;
    std::cout << "Worker 3:" << std::endl;
    employee3.read();
    std::cin >> employee3;
    std::cin.ignore();
    // 5.10
    employee employee4;
    std::cout << "Worker 4:" << std::endl;
    employee4.read();
    std::cin >> employee4;
    // 5.11
    std::ofstream ofs;
    std::string filename;
    std::cout << "Filename: ";
    std::getline(std::cin, filename);
    ofs.open(filename);
    if (!ofs.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        exit(1);
    }
    ofs << employee1 << std::endl;
    ofs << employee2 << std::endl;
    ofs << employee3 << std::endl;
    ofs << employee4 << std::endl;
    ofs.close();
    // 5.13
    std::array<employee, 4> employees;
    std::ifstream ifs{filename};
    if (!ifs.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        exit(1);
    }
    for (auto &worker: employees) {
        ifs >> worker;
    }
    // 5.14
    std::ranges::sort(employees, [](const employee &a, const employee &b) {
        return a.get_birth_date() < b.get_birth_date();
    });
    for (const auto &e: employees) {
        std::cout << e << std::endl;
    }
}