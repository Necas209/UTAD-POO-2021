#include "person.h"
#include <chrono>
#include <clocale>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
    person p1{"Jonas Culatra",
              std::chrono::year{1987} / std::chrono::September / 20,
              "Rua da direita no. 2"};
    person p2("Joni Rato",
              std::chrono::year{1990} / std::chrono::February / 4,
              "Rua da esquerda no. 3");
    setlocale(LC_ALL, "");
    // c)
    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    // d)
    std::string address;
    std::cout << "New address for p2: ";
    std::getline(std::cin, address);
    p2.set_address(address);
    // e)
    date birth_date;
    std::cout << "New birth date for p2: ";
    std::chrono::from_stream(std::cin, "%Y-%m-%d", birth_date);
    std::cin.ignore();
    p2.set_birth_date(birth_date);
    // f)
    person p3;
    std::cout << "p3: ";
    std::cin >> p3;
    std::cin.ignore();
    // g)
    person p4;
    std::cout << "person 4: " << std::endl;
    p4.read();
    std::cout << "person 4:" << std::endl;
    p4.print();
    // h)
    if (p3 == p4) {
        std::cout << "p3 and p4 are the same person." << std::endl;
    } else {
        std::cout << "p3 and p4 are different people." << std::endl;
    }
    // i)
    if (p3.is_younger(p4)) {
        std::cout << "p3 is younger than p4." << std::endl;
    } else {
        std::cout << "p3 is older than p4." << std::endl;
    }
    // j)
    std::string filename;
    std::cout << "Filename: ";
    std::getline(std::cin, filename);
    std::ofstream ofs(filename);
    if (!ofs.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        exit(1);
    }
    ofs << p1 << std::endl;
    ofs << p2 << std::endl;
    ofs << p3 << std::endl;
    ofs << p4 << std::endl;
    ofs.close();
    // l)
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        exit(1);
    }
    std::vector<person> people;
    while (!ifs.eof()) {
        person p;
        ifs >> p >> std::ws;
        people.push_back(p);
    }
    // m)
    date prior_to_1990{std::chrono::year{1990} / std::chrono::January / 1};
    for (auto &p: people) {
        if (p.get_birth_date() < prior_to_1990) {
            std::cout << p << std::endl;
        }
    }
}