#define _CRT_SECURE_NO_WARNINGS
#include <ctime> // livraria que inclui funcoes de tempo
#include <iostream>
#include <fstream>

using namespace std;

class Data
{
private:
	const static char delim = '/'; // delimitador da data, por ex., ':' ou '/'
	int dia;
	int mes;
	int ano;
public:
	Data();
	Data(int dia, int mes, int ano);
	~Data();
	void SetDia(int dia) { this->dia = dia; }
	void SetMes(int mes) { this->mes = mes; }
	void SetAno(int ano) { this->ano = ano; }
	int GetDia(void) { return dia; }
	int GetMes(void) { return mes; }
	int GetAno(void) { return ano; }
	void Show(void);
	void Update(int dia, int mes, int ano);
	bool Igual(Data D);
	void ReadFile(ifstream& ifs);
	void SaveFile(ofstream& ofs);
	bool operator==(const Data& D);
	bool operator!=(const Data& D);
	bool operator<(const Data& D);
	friend ostream& operator<<(ostream& os, const Data& D);
	friend istream& operator>> (istream& is, Data& D);
};
