
// Resolução do exercício 1.2

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num_int;
    float num_real;
    char ch;
    string str;

    cout << "Insira um numero inteiro: ";
    cin >> num_int;
    cout << "Insira um numero real: ";
    cin >> num_real;
    cout << "Insira um caracter: ";
    cin >> ch;
    cout << "Insira uma string: ";
    getline(cin, str);

    cout << "Inteiro inserido: " << num_int << endl;
    cout << "Real inserido: " << num_real << endl;
    cout << "Caracter inserido: " << ch << endl;
    cout << "String inserida: " << str << endl;

    return 0;
}