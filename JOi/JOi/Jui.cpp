#include <iostream>
using namespace std;

class pryamoug {
public:
int a,b;
int getS() 
{
	return a*b;
}
int getP()
{
	return 2*(a+b);
}
};
class MichaelKrug{
public:
	double r;
    double getS1()
	{
		return 3.14159*r*r;
	}
	double getP1()
	{
		return 2*3.14159*r;
	}
};
void main() {
 pryamoug A;
 MichaelKrug B;
 A.a=2;
 A.b=12;
 B.r=3;
 cout << A.getS()<< endl;
 cout << A.getP()<< endl;
 cout << B.getS1()<< endl;
 cout << B.getP1()<< endl;
 system("pause");
}
