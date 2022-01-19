
class Relogio 
{
private: 
	int horas, minutos; 
public: 
	Relogio(void); 
	Relogio(int, int); 
	virtual ~Relogio(void); 
	int getHoras(void) const { return horas; } 
	void setHoras(int _horas) { horas = _horas; }
	int getMinutos(void) const { return minutos; } 
	void setMinutos(int _minutos) { minutos = _minutos; } 
	Relogio operator-(const Relogio Rel) const; // Devolve num relógio a diferença de tempo decorrido. 
};
