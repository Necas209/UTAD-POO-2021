
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a, b;
    ifstream is; // objecto is para abrir o ficheiro em modo de leitura
    ofstream os; // objecto os para abrir o ficheiro em modo de escrita
    // para abrir o ficheiro em modo de escrita e leitura
    // deve usar-se a class fstream
    is.open("dados_ent.txt");
    if (!is.is_open())
    {
        cout << "ERRO: não é possível abrir o ficheiro dados_ent.txt" << endl;
        exit(1);
    }
    os.open("dados_saida.txt");
    if (!os.is_open())
    {
        cout << "ERRO: não é possível abrir o ficheiro dados_saida.txt" << endl;
        exit(1);
    }
    is >> a >> b;
    
    cout << a << endl << b << endl;
    
    os << a * a << endl << b * b << endl;
    is.close(); // fecha o ficheiro associado a is
    os.close(); // fecha o ficheiro associado a os

    system("pause");
    return 0;
}