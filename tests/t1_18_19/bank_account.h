#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "holder.h"
#include "date.h"
#include <iostream>

class bank_account final {
private:
    holder account_holder;
    double balance{};
    date opening_date;
public:
    bank_account() = default;

    bank_account(const holder &account_holder, double balance, date opening_date)
            : account_holder(account_holder), balance(balance), opening_date(opening_date) {}

    ~bank_account() = default;

    void deposit(double amount) {
        if (amount < 0) {
            std::cout << "Invalid amount: " << amount << std::endl;
            std::cout << "Amount must be positive" << std::endl;
            return;
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount < 0) {
            std::cout << "Invalid amount: " << amount << std::endl;
            std::cout << "Amount must be positive" << std::endl;
            return;
        }
        if (balance < amount) {
            std::cout << "Invalid amount: " << amount << "€" << std::endl;
            std::cout << "Amount must be less than balance" << std::endl;
            return;
        }
        balance -= amount;
    }

    [[maybe_unused]]
    void save_transaction(double amount, const std::string &file_name = "movements.txt") {
        std::ofstream ofs(file_name);
        if (!ofs.is_open()) {
            std::cerr << "Error opening file: " << file_name << std::endl;
            return;
        }
        if (amount >= 0)
            deposit(amount);
        else withdraw(amount);
        ofs << opening_date << ';'
            << account_holder.get_id() << ';'
            << amount << ';' << std::endl;
    }

    void print() {
        account_holder.print();
        std::cout << "Client since: " << opening_date << std::endl;
        std::cout << "Current balance: " << balance << "€" << std::endl;
    }

    friend bool operator==(const bank_account &lhs, const bank_account &rhs) {
        return (lhs.account_holder == rhs.account_holder
                && lhs.balance == rhs.balance
                && lhs.opening_date == rhs.opening_date);
    }

    friend bank_account operator+(const bank_account &lhs, const bank_account &rhs) {
        return {
                lhs.account_holder,
                lhs.balance + rhs.balance,
                lhs.opening_date > rhs.opening_date ? lhs.opening_date : rhs.opening_date
        };
    }

    friend std::ostream &operator<<(std::ostream &os, const bank_account &ba) {
        os << ba.account_holder << ';'
           << ba.balance << ';'
           << ba.opening_date << ';';
        return os;
    }
};

#endif // !ACCOUNT_H

