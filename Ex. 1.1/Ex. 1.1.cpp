
// Resolução do exercício 1.1 em C
/*#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int idade;
	char nome[30];
	printf("Escreva o seu nome:\n");
	scanf("%[^\n]", &nome);
	printf("Insira a sua idade:\n");
	scanf("%d", &idade);
	printf("O seu nome e: %s e tem: %d anos\n", nome, idade);
	system("pause");
	return 0;
}*/

// Resolução do exercício 1.1 em C++
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int idade;
	string nome;
	cout << "Escreva o seu nome:" << endl;
	getline(cin, nome);
	cout << "Insira a sua idade:" << endl;
	cin >> idade;
	cout << "O seu nome e: " << nome << " e tem: " << idade << " anos" << endl;
	system("pause");
	return 0;
}