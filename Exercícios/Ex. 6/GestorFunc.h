
#include <iostream>
#include <vector>
#include "Operario.h"
#include "Administrativo.h"

using namespace std;

void LerFuncionarios(vector<Funcionario*>& V);

void CalcularOrdenados(vector<Funcionario*>& V);

// Pesquisa um funcion�rio, por n�mero
// Sim: Retorna o �ndice do funcion�rio
// N�o: Retorna -1
int PesquisarFuncionario(vector<Funcionario*>& V);

void AlterarOrdenado(vector<Funcionario*>& V);

void ApresentarTurnos(vector<Funcionario*>& V);

void AdicionarFuncionario(vector<Funcionario*>& V);

void EliminarFuncionario(vector<Funcionario*>& V);

void GuardarAdministrativos(vector<Funcionario*>& V);

void GuardarOperarios(vector<Funcionario*>& V);

void LibertarVetor(vector<Funcionario*>& V);