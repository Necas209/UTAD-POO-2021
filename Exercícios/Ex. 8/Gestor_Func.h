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

	//a) Ler os dados de N funcion�rios, para a lista, a partir de um ficheiro(ReadFile).
	//b) Listar, no ecr�, a informa��o de todos os funcion�rios(ShowFunc);
	//c) Um m�todo para adicionar um funcion�rio � lista(AddFunc);
	//d) Um m�todo para remover um funcion�rio da lista(RemoveFunc);
	//e) Sobrecarga dos operadores >> e << ;
	//f) Gravar os dados dos funcion�rios para um ficheiro(SaveFile);

	void ReadFile(ifstream& ifs);
	void ShowFunc();
	void AddFunc(Funcionario* F);
	void RemoveFunc(Funcionario* F);
};

