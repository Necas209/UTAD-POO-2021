#include "../Ex. 4/Pessoa.h"
#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Funcionario : public Pessoa
{
private:
	int num_Func;
	string setor;
	float ord_base;
	int h_extra;
	float p_hora_extra;
public:
	// Construtores e Destrutor
	Funcionario();
	Funcionario(string nome, Data dataN, string morada
		, int num_Func, string setor
		, float ord_base, int h_extra, float p_hora_extra);
	virtual ~Funcionario();

	// Métodos de Acesso
	void SetNum_Func(int num_Func) { this->num_Func = num_Func; }
	void SetSetor(string setor) { this->setor = setor; }
	void SetOrd_Base(float ord) { ord_base = ord; }
	void SetH_Extra(int h) { h_extra = h; }
	void SetP_Hora_Extra(float p) { p_hora_extra = p; }
	int GetNum_Func(void) const { return num_Func; }
	string GetSetor(void) const { return setor; }
	float GetOrd_Base(void) const { return ord_base; }
	int GetH_Extra(void) const { return h_extra; }
	float GetP_Hora_Extra(void) const { return p_hora_extra; }

	// Outros Métodos
	virtual void Show(void);
	virtual void ReadK(void);
	virtual void ReadFile(ifstream& ifs);
	virtual void SaveFile(ofstream& ofs);
	virtual float CalculaOrdenado() = 0;

	// Sobrecarga de Operadores
	friend ostream& operator<<(ostream& os, const Funcionario& F);
	friend istream& operator>>(istream& is, Funcionario& F);
};
