#ifndef WORKER_H
#define WORKER_H

#include "../ex5/employee.h"

class worker final : public employee {
private:
    bool works_shift{};
public:
    worker() = default;

    ~worker() override = default;

    [[nodiscard]] bool get_works_shift() const { return works_shift; }

    void print() override {
        employee::print();
        std::cout << "Works shift: " << (works_shift ? "Yes" : "No") << std::endl;
    }

    void read() override {
        employee::read();
        std::cout << "Works shift (1 - Yes, 0 - No): ";
        std::cin >> works_shift;
    }

    double calculate_salary() override {
        double final_salary = base_salary + extra_hours * get_extra_hour_val();
        return works_shift ? final_salary * 1.25 : final_salary;
    }

    [[nodiscard]] double get_extra_hour_val() const override { return 8.0; }

    friend std::ostream &operator<<(std::ostream &os, const worker &w) {
        os << "worker{"
           << static_cast<const employee &>(w)
           << ", works_shift=" << w.works_shift
           << '}';
        return os;
    }

    friend std::istream &operator>>(std::istream &is, worker &w) {
        // Discard the "worker{" part
        is.ignore(7);
        // Read the employee part
        is >> static_cast<employee &>(w);
        // Discard the ", works_shift=" part
        is.ignore(14);
        // Read the works_shift part
        is >> w.works_shift;
        // Discard the "}" part
        is.ignore(1);
        return is;
    }
};

#endif // !WORKER_H

