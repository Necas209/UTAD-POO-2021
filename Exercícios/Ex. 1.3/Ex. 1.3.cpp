#include <iostream>
#include <iomanip>

int main() {
    std::cout << "Trying out std::setw() .............. " << std::endl;
    std::cout << std::setw(10) << 11 << std::endl;
    std::cout << std::setw(10) << 2222 << std::endl;
    std::cout << std::setw(10) << 4 << std::endl;
    std::cout << std::setfill('-') << std::setw(10) << 11 << std::endl;
    system("pause");
    return (0);
}
