#pragma once

#include <iostream>

using namespace std;

class Titular
{
private:
	string nome;
	string morada;
	int numero;

public:
	Titular();
	Titular(string _nome, string _morada, int num);
	~Titular();
	string GetNome() { return nome; }
	string GetMorada() { return morada; }
	int GetNumero() { return numero; }
	void SetNome(string _nome) { nome = _nome; }
	void SetMorada(string _morada) { morada = _morada; }
	void SetNumero(int num) { numero = num; }
	void Show();
	bool operator==(Titular T);
};

