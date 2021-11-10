#include "../Ex. 3/Data.h"
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
	Pessoa();
	Pessoa(string nome, Data dataN, string morada);
	~Pessoa();
	void SetNome(string nome) { this->nome = nome; }
	void SetDataN(Data dataN) { this->dataN = dataN; }
	void SetMorada(string morada) { this->morada = morada; }
	string GetNome(void) { return nome; }
	Data GetDataN(void) { return dataN; }
	string GetMorada(void) { return morada; }
	void Show(void);
	void ReadK(void);
	void MaisNovo(Pessoa& P);
	void ReadFile(ifstream& ifs);
	void SaveFile(ofstream& ofs);
	bool operator==(const Pessoa& P);
	bool operator!= (const Pessoa& P);
	friend ostream& operator<<(ostream& os, const Pessoa& P);
	friend istream& operator>>(istream& is, Pessoa& P);
};

