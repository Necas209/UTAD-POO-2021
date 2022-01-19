#include "Gestor_Func.h"

Gestor_Func::Gestor_Func()
{
}

Gestor_Func::Gestor_Func(list<Funcionario*> funcs)
{
	Funcs = funcs;
}

Gestor_Func::~Gestor_Func()
{
	list<Funcionario*>::iterator it = Funcs.begin();
	while (it != Funcs.end())
	{
		delete (*it);
		++it;
	}

	//for (Funcionario* f : Funcs)
	//{
	//	delete f;
	//}
	Funcs.clear();
}

void Gestor_Func::ReadFile(ifstream& ifs)
{
	while (!ifs.eof())
	{
		Funcionario* F;
		string tipo;
		getline(ifs, tipo, ':');
		if (tipo == "O")
		{
			F = new Operario;
		}
		else
		{
			F = new Administrativo;
		}
		F->ReadFile(ifs);
		Funcs.push_back(F);
	}
}

void Gestor_Func::ShowFunc()
{
	list<Funcionario*>::iterator it;
	it = Funcs.begin();
	while (it != Funcs.end())
	{
		(*it)->Show();
	}
}

void Gestor_Func::AddFunc(Funcionario* F)
{
	Funcs.push_back(F);
	// No início
	// Funcs.push_front(F);
}

void Gestor_Func::RemoveFunc(Funcionario* F)
{
	auto it = find(Funcs.begin(), Funcs.end(), F);
	delete (*it);
	Funcs.erase(it);
}
