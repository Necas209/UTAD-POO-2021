
// Resolução do exercício 1.3

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "ENSAIO do setw() .............. " << endl;
	cout << setw(10) << 11 << endl;
	cout << setw(10) << 2222 << endl;
	cout << setw(10) << 4 << endl;
	cout << setfill('-') << setw(10) << 11 << endl;

	system("pause");
	return (0);
}
