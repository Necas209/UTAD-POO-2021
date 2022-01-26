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

	//for (auto& func : Funcs)
	//{
	//	delete func;
	//}
	Funcs.clear();
}

void Gestor_Func::SaveFile(ofstream& ofs)
{
	for (auto& func : Funcs)
	{
		if (dynamic_cast<Operario*>(func) != nullptr)
		{
			ofs << "O:";
		}
		else if(dynamic_cast<Administrativo*>(func) != nullptr)
		{
			ofs << "A:";
		}
		func->SaveFile(ofs);
		ofs << endl;
	}
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
		ifs >> ws;
	}
}

void Gestor_Func::ShowFunc()
{
	list<Funcionario*>::iterator it;
	it = Funcs.begin();
	while (it != Funcs.end())
	{
		(*it)->Show();
		cout << endl;
		++it;
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
	if (it != Funcs.end())
	{
		delete (*it);
		Funcs.erase(it);
	}
}

void Gestor_Func::RemoveFunc(string nome)
{
	auto F = [&](Funcionario* func) { return func->GetNome() == nome; };
	auto it = find_if(Funcs.begin(), Funcs.end(), F);
	if (it != Funcs.end())
	{
		delete (*it);
		Funcs.erase(it);
	}
}

ostream& operator<<(ostream& os, const Gestor_Func& G)
{
	for (auto& func : G.Funcs)
	{
		os << func;
	}
	return os;
}

istream& operator>>(istream& is, Gestor_Func& G)
{
	int tipo;
	Funcionario* F;
	cout << "Tipo de Funcionário:" << endl;
	cout << "1 - Operário" << endl;
	cout << "2 - Administrativo" << endl;
	(is >> tipo).ignore();
	if (tipo == 1)
	{
		F = new Operario;
	}
	else
	{
		F = new Administrativo;
	}
	is >> *F;
	G.AddFunc(F);
	return is;
}
