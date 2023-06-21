#include "employee.h"
#include <array>
#include <clocale>
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    // 5.4
    employee worker1("Joca Gaio", date(20, 9, 1987), "Rua da direita n 2",
                     25023, "Pintura");
    employee worker2("Ana Rola", date(4, 2, 1990), "Rua da esquerda n 3",
                     25024, "Comercial");
    setlocale(LC_ALL, "");
    // 5.5
    std::cout << "Worker 1:" << std::endl;
    worker1.print();
    std::cout << "Worker 2:" << std::endl;
    worker2.print();
    // 5.6
    worker1.set_address("Rua do meio n 4");
    worker1.set_sector("Ferragem");
    // 5.7
    date birth_date = worker2.get_birth_date();
    date new_birth_date(5, birth_date.get_month(), birth_date.get_year());
    worker2.set_birth_date(new_birth_date);
    // 5.9
    employee worker3, worker4;
    std::cout << "Worker 3:" << std::endl;
    //worker3.read();
    std::cin >> worker3;
    std::cout << "Worker 4:" << std::endl;
    //worker4.read();
    std::cin >> worker4;
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
    ofs << worker1 << std::endl;
    ofs << worker2 << std::endl;
    ofs << worker3 << std::endl;
    ofs << worker4 << std::endl;
    ofs.close();
    // 5.13
    std::array<employee, 4> workers;
    std::ifstream ifs{filename};
    if (!ifs.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        exit(1);
    }
    for (auto &worker: workers) {
        ifs >> worker;
    }
    // 5.14
    std::ranges::sort(workers, [](const employee &a, const employee &b) {
        return a.get_birth_date() < b.get_birth_date();
    });
    for (const auto &worker: workers) {
        std::cout << worker << std::endl;
    }
}