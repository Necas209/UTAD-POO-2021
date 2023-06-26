#include <iostream>
#include <iomanip>

using std::ios;

int main() {
    std::cout << "General precision .............................. " << std::endl;
    std::cout << "5 digits: " << std::setprecision(5) << 1234.537 << std::endl;
    std::cout << "6 digits: " << std::setprecision(6) << 1234.537 << std::endl;
    std::cout << "Decimal precision .............................. " << std::endl;
    std::cout.setf(ios::floatfield, ios::fixed);
    std::cout << "2 digits: " << std::setprecision(2) << 1234.537 << std::endl;
    std::cout << "5 digits: " << std::setprecision(5) << 1234.537 << std::endl;
    system("pause");
    return 0;
}
