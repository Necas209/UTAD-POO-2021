#include "person.h"

void person::print() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Birth date: " << birth_date << std::endl;
    std::cout << "Address: " << address << std::endl;
}

void person::read() {
    std::cout << "Name: ";
    std::getline(std::cin, name);
    std::cout << "Birth date: ";
    std::chrono::from_stream(std::cin, "%Y-%m-%d", birth_date);
    std::cin.ignore();
    std::cout << "Address: ";
    std::getline(std::cin, address);
}

std::ostream &operator<<(std::ostream &os, const person &p) {
    os << "person{"
       << "name='" << p.name << '\''
       << ", birth_date=" << p.birth_date
       << ", address='" << p.address << '\''
       << '}';
    return os;
}

std::istream &operator>>(std::istream &is, person &p) {
    // Discard "person{" from the input stream
    is.ignore(7);
    // Discard "name='" from the input stream
    is.ignore(6);
    // Read the name
    std::getline(is, p.name, '\'');
    // Discard ", birth_date=" from the input stream
    is.ignore(13);
    // Read the birthdate
    std::chrono::from_stream(is, "%Y-%m-%d", p.birth_date);
    // Discard ", address='" from the input stream
    is.ignore(11);
    // Read the address
    std::getline(is, p.address, '\'');
    // Discard "}" from the input stream
    is.ignore(1);
    return is;
}
