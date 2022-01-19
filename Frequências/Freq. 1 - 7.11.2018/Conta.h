#pragma once
#include "Titular.h"
#include "../../Exerc�cios/Ex. 3/Data.h"

class Conta
{
private:
	Titular titular; // Composi��o
	float saldo;
	Data data_abertura; // Composi��o
public:
	Conta();
	Conta(Titular _titular, float _saldo, Data _data);
	~Conta();
	void Deposito(int valor);
	void Levantamento(int valor);
	void SaveFile(int valor);
	bool operator==(Conta C);
	Conta operator+(Conta C);
	friend ostream& operator<<(ostream& os, Conta C);
	friend istream& operator>>(istream& is, Conta& C);
};

