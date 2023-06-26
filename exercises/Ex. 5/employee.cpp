#include "employee.h"

void employee::print() {
    person::print();
    std::cout << "ID: " << id << std::endl;
    std::cout << "Sector: " << sector << std::endl;
    std::cout << "Base salary: " << base_salary << std::endl;
    std::cout << "Extra hours: " << extra_hours << std::endl;
}

void employee::read() {
    person::read();
    std::cout << "ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Sector: ";
    getline(std::cin, sector);
    std::cout << "Base salary: ";
    std::cin >> base_salary;
    std::cin.ignore();
    std::cout << "Extra hours: ";
    std::cin >> extra_hours;
    std::cin.ignore();
}

std::ostream &operator<<(std::ostream &os, const employee &w) {
    os << "employee{"
       << (person &) w
       << ", id=" << w.id
       << ", sector='" << w.sector << '\''
       << ", base_salary=" << w.base_salary
       << ", extra_hours=" << w.extra_hours
       << '}';
    return os;
}

std::istream &operator>>(std::istream &is, employee &w) {
    // Discard the opening 'employee{' part
    is.ignore(9);
    // Read the person part
    is >> static_cast<person &>(w);
    // Discard the ', id=' part
    is.ignore(5);
    // Read the ID
    is >> w.id;
    // Discard the ", sector='" part
    is.ignore(10);
    // Read the sector
    std::getline(is, w.sector, '\'');
    // Discard the ', base_salary=' part
    is.ignore(14);
    // Read the base salary
    is >> w.base_salary;
    // Discard the ', extra_hours=' part
    is.ignore(14);
    // Read the extra hours
    is >> w.extra_hours;
    // Discard the closing '}' part
    is.ignore(1);
    return is;
}

