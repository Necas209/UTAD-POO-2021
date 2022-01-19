#include "Relogio.h" 
#include <iostream>

using namespace std;

class Empregado 
{ 
private: 
	string nome; 
	Relogio DeEntrada; 
	Relogio DeSaida; 
public:
	Empregado(void);
	virtual ~Empregado(void);
	Empregado(string _nome, Relogio RE, Relogio RS);
	string getNome() {return nome;}
	void setNome(string _nome) {this->nome = _nome;}
	Relogio get_DeEntrada(){return DeEntrada;}
	Relogio get_DeSaida(){return DeSaida;} 
	void set_DeEntrada(Relogio R){DeEntrada = R;}
	void set_DeSaida(Relogio R){DeSaida = R;}
	// Calcula as hora de trabalho fazendo a diferença entre os relógio DeEntrada e de DeSaida. Ignora os minutos 
	int Calcula_horasDeTrabalho(); 
	virtual float Calculo_Ordenado_Dia() = 0;

	virtual void Show();
	virtual void ReadK();
	friend ostream& operator<<(ostream& os, const Empregado& E);
};
