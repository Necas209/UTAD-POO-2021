#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "../Ex. 5/employee.h"

class administrator final : public employee {
public:
    administrator() = default;

    ~administrator() override = default;

    double calculate_salary() override { return base_salary + extra_hours * get_extra_hour_val(); }

    [[nodiscard]] double get_extra_hour_val() const override { return 10.0f; }

    friend std::ostream &operator<<(std::ostream &os, const administrator &admin) {
        os << "administrator{"
           << static_cast<const employee &>(admin)
           << "}";
        return os;
    }

    friend std::istream &operator>>(std::istream &is, administrator &a) {
        // Discard the "administrator{" part
        is.ignore(14);
        // Read the employee part
        is >> static_cast<employee &>(a);
        // Discard the "}" part
        is.ignore(1);
        return is;
    }
};

#endif /* ADMINISTRATOR_H */