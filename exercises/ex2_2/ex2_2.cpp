#include <iostream>
#include <fstream>

int main() {
    // Open file stream for reading and writing
    std::ifstream ifs{"../dados_ent.txt"};
    std::ofstream ofs{"../dados_saida.txt"};
    // Check if files were opened correctly
    if (!ifs.is_open()) {
        std::cout << "Error: cannot open file dados_ent.txt" << std::endl;
        exit(1);
    }
    if (!ofs.is_open()) {
        std::cout << "Error: cannot open file dados_saida.txt" << std::endl;
        exit(1);
    }
    int a = 0, b = 0;
    ifs >> a >> b;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    ofs << a * a << std::endl;
    ofs << b * b << std::endl;
    system("pause");
    return 0;
}