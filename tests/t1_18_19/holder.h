#ifndef HOLDER_H
#define HOLDER_H

#include <iostream>

class holder final {
private:
    int id{};
    std::string name;
    std::string address;
public:
    holder() = default;

    holder(int id, std::string name, std::string address)
            : id(id), name(std::move(name)), address(std::move(address)) {}

    ~holder() = default;

    int get_id() const { return id; }

    [[maybe_unused]] std::string get_name() { return name; }

    [[maybe_unused]] std::string get_address() { return address; }

    void print() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Address: " << address << std::endl;
    }

    friend bool operator==(const holder &lhs, const holder &rhs) {
        return (lhs.name == rhs.name
                && lhs.address == rhs.address
                && lhs.id == rhs.id);
    }

    friend std::ostream &operator<<(std::ostream &os, const holder &h) {
        os << h.id << ';' << h.name << ';' << h.address << ';';
        return os;
    }
};

#endif // !HOLDER_H

