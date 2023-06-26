#include "bank_account.h"
#include <iostream>
#include <Windows.h>

int main() {
    // set encoding to UTF-8 (Windows)
    SetConsoleOutputCP(CP_UTF8);

    holder holder1(12324328, "Andre Sousa", "Vila Real, PT");
    holder holder2(145544545, "Victor Filipe", "Vila Real, PT");
    date opening_date(17, 11, 2021);

    bank_account c1(holder1, 600.0, opening_date);
    bank_account c2(holder2, 0.0, opening_date);

    std::cout << "Bank account 1, before withdraw:" << std::endl;
    c1.print();
    std::cout << "Bank account 2, before deposit:" << std::endl;
    c2.print();
    c1.withdraw(174.0);
    c2.deposit(174.0);
    std::cout << "Bank account 1, after withdraw:" << std::endl;
    c1.print();
    std::cout << "Bank account 2, after deposit:" << std::endl;
    c2.print();
}
