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
    std::cin >> birth_date;
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
    std::string input;
    std::getline(is, input);
    // Deserialize the input string
    size_t nameStart = input.find("name='") + 6;
    size_t nameEnd = input.find('\'', nameStart);
    p.name = input.substr(nameStart, nameEnd - nameStart);
    size_t birthDateStart = input.find("birth_date=") + 11;
    size_t birthDateEnd = input.find(',', birthDateStart);
    std::string bds = input.substr(birthDateStart, birthDateEnd - birthDateStart);
    std::istringstream(bds) >> p.birth_date;
    size_t addressStart = input.find("address='") + 9;
    size_t addressEnd = input.find('\'', addressStart);
    p.address = input.substr(addressStart, addressEnd - addressStart);
    return is;
}
