#include <iostream>
#include <random>
#include <array>
#include "hired_employee.h"
#include "staff.h"


int main() {
    // Setup random engine
    auto random = std::random_device();
    auto random_engine = std::mt19937(random());
    auto random_distribution = std::uniform_int_distribution<>(0, 1);
    // Ex. 7.
    std::array<employee *, 50> employees{};
    for (auto &e: employees) {
        // random(0, 1)
        auto random_number = random_distribution(random_engine);
        if (random_number == 0) {
            e = new staff;
        } else {
            e = new hired_employee;
        }
        e->read();
    }
    // Ex. 8.
    for (auto &e: employees) {
        std::cout << "Employee: " << std::endl;
        std::cout << "Name: " << e->get_name() << std::endl;
        std::cout << "Day salary: " << e->salary_per_day() << std::endl;
    }
}