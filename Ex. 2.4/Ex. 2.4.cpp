// Resolução do exercício 2.4

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct aluno
{
    string nome;
    int idade;
    int numero;
}Aluno;

int main()
{
    ifstream file;
    file.open("alunos.txt");
    if (file.is_open())
    {
        Aluno tmp;
        char delim;
        while (!file.eof())
        {
            getline(file, tmp.nome, ';');
            file >> tmp.idade >> delim;
            file >> tmp.numero >> ws;
            cout << "Nome: " << tmp.nome << endl;
            cout << "Idade: " << tmp.idade << endl;
            cout << "Número: " << tmp.numero << endl;
        }
        file.close();
        return 0;
    }
    exit(1);
}