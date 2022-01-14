#include "GestorNum.h"

GestorNum::GestorNum()
{
}

GestorNum::GestorNum(list<int> l)
	:lista(l)
{
}

GestorNum::~GestorNum()
{
	lista.clear();
}

void GestorNum::InserirIni(int num)
{
	lista.push_front(num);
}

void GestorNum::InserirFim(int num)
{
	lista.push_back(num);
}

void GestorNum::Remover(int num)
{
	lista.remove(num);
}

bool GestorNum::Existe(int num)
{
	list<int>::iterator it = find(lista.begin(), lista.end(), num);
	// Se não encontrar, it será igual a lista.end()
	return (it != lista.end());
}

int GestorNum::GetPos(int num)
{
	int i = 0;
	// 1.ª Forma
	for (int& n : lista)
	{
		if (n == num)
		{
			return i;
		}
		++i;
	}
	return -1;
	// 2.ª Forma
	list<int>::iterator p = lista.begin();
	while (p != lista.end())
	{
		if (*p == num)
		{
			return i;
		}
		++p;
		++i;
	}
	return -1;
}

void GestorNum::Show(void)
{
	// 1.ª Forma
	for (int& n : lista)
	{
		cout << n << ' ';
	}
	// 2.ª Forma
	for (list<int>::iterator p = lista.begin(); p != lista.end(); p++)
	{
		cout << *p << ' ';
	}
	// 3.ª Forma
	list<int>::iterator p = lista.begin();
	while(p != lista.end())
	{
		cout << *p << ' ';
		++p;
	}
}
