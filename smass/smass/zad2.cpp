#include <iostream>
#include <locale.h>
using namespace std;
int main ( )
{	setlocale(LC_ALL, "RUS");
	int n1, n2, mass1[20], mass2[20], mass3[30];
	cout << "¬ведите n-чисел первого массива: ";
	cin >> n1;
	cout << "¬ведите n-чисел второго массива: ";
	cin >> n2;
	cout << "¬ведите 1-ый массив: ";
	for (int i = 0; i<n1; i++) { cin >> mass1[i];}
	cout << "¬ведите 2-ой массив: ";
	for (int i = 0; i<n2; i++) { cin >> mass2[i];}

	for (int i = 0; i<n1+n2; i++)
	{ for (int j = 0; j<n1; j++)
		{for (int k = 0; k<n2; k++)
	{ if (i%2 == 0) {mass3[i] = mass2[k];} else {mass3[i] = mass1[j];} }
	}
	}
	
	cout << "3-ий массив равен: ";
	for (int i = 0; i<n1+n2; i++)
	{	cout << mass3[i]; }
	system("pause");
}