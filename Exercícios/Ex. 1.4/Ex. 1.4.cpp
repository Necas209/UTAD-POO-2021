
// Resolução do exercício 1.4

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "Precisao global ....................... " << endl;
	cout << "5 digitos, parte inteira e decimal " << setprecision(5) << 1234.537 << endl;
	cout << "6 digitos parte inteira e decimal " << setprecision(6) << 1234.537 << endl << endl;

	cout << "Precisao da parte decimal ....................... " << endl;
	cout.setf(ios::floatfield, ios::fixed);
	cout << "2 digitos na parte decimal " << setprecision(2) << 1234.537 << endl;
	cout << "5 digitos na parte decimal " << setprecision(5) << 1234.537 << endl;

	system("pause");
	return 0;
}
