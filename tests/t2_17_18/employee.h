#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <chrono>

using time_point = std::chrono::time_point<std::chrono::system_clock>;

class employee {
private:
    std::string name;
    time_point entry_time;
    time_point exit_time;
public:
    employee() = default;

    employee(std::string name, time_point entry_time, time_point exit_time)
            : name(std::move(name)), entry_time(entry_time), exit_time(exit_time) {}

    virtual ~employee() = default;

    [[nodiscard]] std::string get_name() const { return name; }

    void set_name(std::string name_) { this->name = std::move(name_); }

    [[nodiscard]] time_point get_entry_time() const { return entry_time; }

    void set_entry_time(time_point entry_time_) {
        if (entry_time_ > exit_time) {
            throw std::invalid_argument("Entry time must be before exit time");
        }
        this->entry_time = entry_time_;
    }

    [[nodiscard]] time_point get_exit_time() const { return exit_time; }

    void set_exit_time(time_point exit_time_) {
        if (exit_time_ < entry_time) {
            throw std::invalid_argument("Exit time must be after entry time");
        }
        this->exit_time = exit_time_;
    }

    [[nodiscard]] int hours_worked() const {
        auto hours = std::chrono::duration_cast<std::chrono::hours>(exit_time - entry_time);
        return hours.count();
    }

    [[nodiscard]] virtual double salary_per_day() const = 0;

    virtual void print() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Entry time: " << entry_time << std::endl;
        std::cout << "Exit time: " << exit_time << std::endl;
    }

    virtual void read() {
        std::cout << "Name: ";
        std::getline(std::cin, name);
        std::cout << "Entry time: ";
        // std::cin >> entry_time;
        std::cout << "Exit time: ";
        // std::cin >> exit_time;
        std::cin.ignore();
    }

    friend std::ostream &operator<<(std::ostream &os, const employee &e) {
        os << "Name: " << e.name << std::endl;
        os << "Entry time: " << e.entry_time << std::endl;
        os << "Exit time: " << e.exit_time << std::endl;
        return os;
    }
};

#endif //EMPLOYEE_H
