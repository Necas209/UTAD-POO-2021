// Resolução do exercício 2.3

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct aluno
{
    string nome;
    int idade = 0;
    int numero = 0;
};
typedef aluno Aluno;

int main()
{
    ofstream file;
    Aluno alunos[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "Nome: ";
        getline(cin, alunos[i].nome);
        cout << "Idade: ";
        cin >> alunos[i].idade;
        cout << "Número: ";
        cin >> alunos[i].numero;
        cin.ignore();
    }
    file.open("alunos.txt");
    if (file.is_open())
    {
        for (int i = 0; i < 3; i++)
        {
            file << alunos[i].nome << ';' << alunos[i].idade << ';' << alunos[i].numero << endl;
        }
        file.close();
        return 0;
    }
    exit(1);
}