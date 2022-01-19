
#include "Conta.h"

int main()
{
	Titular t1("Andre Sousa", "Vila Real, PT", 12324328);
	Titular t2("Vitor Filipe", "Vila Real, PT", 145544545);
	Data d(17, 11, 2021);
	Conta c1(t1, 600, d);
	Conta c2(t2, 0, d);

	cout << "Conta C1: " << c1 << endl;
	cout << "Conta C2: " << c2 << endl;
	c1.Levantamento(174);
	c2.Deposito(174);
	cout << "Conta C1: " << c1 << endl;
	cout << "Conta C2: " << c2 << endl;
}
