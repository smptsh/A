#include <stdafx.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string line;
	int count=0;
	char searchkey='a';
	cout << "enter string: ";
	getline(cin,line);
	for (unsigned int i=0; i<line.length(); i++)
		if(line[i] ==searchkey)
			count++;
	cout << "string has " << count << " symbol(s) " << """ <<searchkey << ""!" << endl;
	system ("pause");

}