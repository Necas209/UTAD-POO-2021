#include "Funcionario.h"

Funcionario::Funcionario()
	:num_Func(0), setor("")
{
}

Funcionario::Funcionario(string nome, Data dataN, string morada, int num_Func, string setor)
	:Pessoa(nome, dataN, morada), num_Func(num_Func), setor(setor)
{
}

Funcionario::~Funcionario()
{
}

void Funcionario::Show(void)
{
	Pessoa::Show();
	cout << "Numero: " << num_Func << endl;
	cout << "Setor: " << setor << endl;
}
