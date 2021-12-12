#include "../Ex. 4/Pessoa.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Funcionario : public Pessoa
{
private:
	int num_Func;
	string setor;
public:
	// Construtores e Destrutor
	Funcionario();
	Funcionario(string nome, Data dataN, string morada, int num_Func, string setor);
	virtual ~Funcionario();

	// Métodos de Acesso
	void SetNum_Func(int num_Func) { this->num_Func = num_Func; }
	void SetSetor(string setor) { this->setor = setor; }
	int GetNum_Func(void) { return num_Func; }
	string GetSetor(void) { return setor; }

	// Outros Métodos
	virtual void Show(void);
	virtual void ReadFile(ifstream& ifs);
	virtual void SaveFile(ofstream& ofs);

	// Sobrecarga de Operadores
	friend ostream& operator<<(ostream& os, const Funcionario& F);
	friend istream& operator>>(istream& is, Funcionario& F);
};
