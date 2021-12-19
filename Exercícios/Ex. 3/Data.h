
#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <ctime> // livraria que inclui funcoes de tempo
#include <iostream>
#include <fstream>

using namespace std;

class Data
{
private:
	// delimitador da data, por ex., ':' ou '/'
	static const char delim = '/';
	int dia;
	int mes;
	int ano;
public:
	// Construtores e Destrutor
	Data();
	Data(int dia, int mes, int ano);
	~Data();

	// Métodos de Acesso
	void SetDia(int dia) { this->dia = dia; }
	void SetMes(int mes) { this->mes = mes; }
	void SetAno(int ano) { this->ano = ano; }
	int GetDia(void) const { return dia; }
	int GetMes(void) const { return mes; }
	int GetAno(void) const { return ano; }

	// Outros Métodos
	void Show(void);
	void Update(int dia, int mes, int ano);
	bool Igual(Data D);
	void ReadFile(ifstream& ifs);
	void SaveFile(ofstream& ofs);

	// Operadores
	bool operator==(const Data& D);
	bool operator!=(const Data& D);
	bool operator<(const Data& D);
	bool operator>(const Data& D);
	bool operator<=(const Data& D);
	bool operator>=(const Data& D);
	Data& operator++(void);
	Data& operator++(int);
	friend ostream& operator<<(ostream& os, const Data& D);
	friend istream& operator>>(istream& is, Data& D);
};

