#include "Titular.h"

Titular::Titular()
{
	nome = "";
	morada = "";
	numero = 0;
}

Titular::Titular(string _nome, string _morada, int num)
{
	nome = _nome;
	morada = _morada;
	numero = num;
}

Titular::~Titular() 
{
}

void Titular::Show()
{
	cout << "Nome: " << nome << endl;
	cout << "Morada: " << morada << endl;
}

bool Titular::operator==(Titular T)
{
	return (nome == T.nome 
		&& morada == T.morada
		&& numero == T.numero);
}