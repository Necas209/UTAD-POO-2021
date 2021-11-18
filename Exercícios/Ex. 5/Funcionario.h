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
	Funcionario();
	Funcionario(string nome, Data dataN, string morada, int num_Func, string setor);
	~Funcionario();
	void SetNum_Func(int num_Func) { this->num_Func = num_Func; }
	void SetSetor(string setor) { this->setor = setor; }
	int GetNum_Func(void) { return num_Func; }
	string GetSetor(void) { return setor; }
	void Show(void);
};
