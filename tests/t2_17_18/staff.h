#ifndef STAFF_H
#define STAFF_H

#include "employee.h"
#include <iostream>

class staff final : public employee {
private:
    int id{};
public:
    staff() = default;

    staff(int id, std::string name, time_point entry_time, time_point exit_time) :
            employee(std::move(name), entry_time, exit_time), id(id) {}

    ~staff() override = default;

    [[nodiscard]] int get_id() const { return id; }

    [[nodiscard]] double salary_per_day() const override {
        auto hours = hours_worked();
        if (hours <= 8)
            return 5 * hours;
        return 40 + (hours - 8) * 5 * 1.25;
    }

    void read() override {
        employee::read();
        std::cout << "ID: ";
        std::cin >> id;
    }

    [[nodiscard]]

    friend std::ostream &operator<<(std::ostream &os, const staff &s) {
        os << (employee &) s;
        return os;
    }
};

#endif //STAFF_H