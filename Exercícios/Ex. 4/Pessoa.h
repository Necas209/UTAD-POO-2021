#include "../Ex. 3/Data.h"
#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Pessoa
{
private:
	string nome;
	Data dataN;
	string morada;
public:
	// Construtores (defeito e com parâmetros) e Destrutor
	Pessoa();
	Pessoa(string nome, Data dataN, string morada);
	virtual ~Pessoa();
	
	// Métodos de Acesso: Setters e Getters
	void SetNome(string nome) { this->nome = nome; }
	void SetDataN(Data dataN) { this->dataN = dataN; }
	void SetMorada(string morada) { this->morada = morada; }
	string GetNome(void) const { return nome; }
	Data GetDataN(void) const { return dataN; }
	string GetMorada(void) const { return morada; }
	
	// Outros Métodos
	virtual void Show(void);
	virtual void ReadK(void);
	void MaisNovo(Pessoa& P);
	virtual void ReadFile(ifstream& ifs);
	virtual void SaveFile(ofstream& ofs);
	
	// Sobrecarga de Operadores
	virtual bool operator==(const Pessoa& P);
	virtual bool operator!= (const Pessoa& P);
	friend ostream& operator<<(ostream& os, const Pessoa& P);
	friend istream& operator>>(istream& is, Pessoa& P);
};

