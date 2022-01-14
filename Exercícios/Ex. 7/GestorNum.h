#pragma once
#include <iostream>
#include <list>

using namespace std;

class GestorNum
{
private:
	list<int> lista;
public:
	// Construtores e Destrutor
	GestorNum();
	GestorNum(list<int> l);
	virtual ~GestorNum();

	// M�todos de Acesso
	void SetLista(list<int> l) { lista = l; }
	list<int> GetLista(void) const { return lista; }
	int GetSize(void) const { return lista.size(); }

	// Outros M�todos
	
	// Inserir no in�cio
	void InserirIni(int num);
	// Inserir no fim
	void InserirFim(int num);
	// Remover todos os elementos iguais a 'num'
	void Remover(int num);
	// Verificar se 'num' existe na lista
	bool Existe(int num);
	// Obter posi��o absoluta do 1.� elemento igual a 'num'
	int GetPos(int num);
	// Mostrar todos os elementos da lista no ecr�
	void Show(void);
};

