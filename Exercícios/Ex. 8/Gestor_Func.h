#pragma once
#include <list>
#include "../Ex. 6/Operario.h"
#include "../Ex. 6/Administrativo.h"

class Gestor_Func
{
private:
	list<Funcionario*> Funcs;
public:
	Gestor_Func();
	Gestor_Func(list<Funcionario*> funcs);
	virtual ~Gestor_Func();

	void SetFuncs(list<Funcionario*> funcs) { Funcs = funcs; }
	list<Funcionario*> GetFuncs() const { return Funcs; }

	//a) Ler os dados de N funcionários, para a lista, a partir de um ficheiro(ReadFile).
	//b) Listar, no ecrã, a informação de todos os funcionários(ShowFunc);
	//c) Um método para adicionar um funcionário à lista(AddFunc);
	//d) Um método para remover um funcionário da lista(RemoveFunc);
	//e) Sobrecarga dos operadores >> e << ;
	//f) Gravar os dados dos funcionários para um ficheiro(SaveFile);

	void ReadFile(ifstream& ifs);
	void ShowFunc();
	void AddFunc(Funcionario* F);
	void RemoveFunc(Funcionario* F);
};

