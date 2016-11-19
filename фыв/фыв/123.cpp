#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<windows.h>
#include<ctime>
using namespace std;
class MyTimer{
	LARGE_INTEGER time1, time2, performance_frequency;
	double value;
public:
	MyTimer():value(0){	
		QueryPerformanceFrequency(&performance_frequency);	
	} 
	void Start(){	
		QueryPerformanceCounter(&time1);
	}
	void End(){
		QueryPerformanceCounter(&time2);
	}
	double GetTime(){
		return (time2.QuadPart - time1.QuadPart)/(double)performance_frequency.QuadPart;
	}
};
void main(){
	setlocale(LC_ALL,"rus");
	std::ios::sync_with_stdio(false);
	MyTimer timer;
	int n,obmen,k,h;
	for (int t = 1; t < 10; t++){
		switch (t) {
			case 1: n=100; break;
			case 2: n=500; break;
			case 3: n=750; break;
			case 4: n=1000; break;
			case 5: n=2500; break;
			case 6: n=5000; break;
			case 7: n=10000; break;
			case 8: n=20000; break;
			case 9: n=30000; break;
		}
	cout << "	ТЕСТ# " << t << " | Количествоэлементов: " << n << endl << endl;
	int *a=new int[n];
	int *b=new int[n];	
	int *a_izvl=new int[n];
	int *a_obmen=new int[n];
	srand(time(NULL));
	for(int i = 0; i< n; i++) 
		a[i]=rand()%100;
	
	for (int i = 0; i<n; i++){
		a_izvl[i]=a[i];
		a_obmen[i]=a[i];
	}
	for(int m = 1; m < 5; m++){
		switch(m){
		case 1: 
			cout << " ПОДСЧЁТОМ";
			k=0;
			timer.Start();
			for(int i = 0; i<n; i++){
				k = 0;
				for(int j = 0; j < n; j++){
					if (a[i]>a[j]) k++;
				}
				while (b[k] == a[i]) k++;
				b[k]=a[i];
			}
			timer.End();
			cout << " | Затраченноевремя: " << fixed << setprecision(7) << timer.GetTime() << endl;
			cout << "\n";					
		break;
		case 2: 
			cout << " ВКЛЮЧЕНИЕМ";
			obmen=0;
			for(int i = 0; i<n; i++)
				b[i]=0;
			//n2=0;
			timer.Start();
			b[0]=a[0];
			h=1;
			for(int i = 1; i<n; i++){
				for(int j=0; j<h; j++){
					if (a[i]<b[j]){
						for (int r=h;r>j;r--){
							obmen=b[r];
							b[r]=b[r-1];
							b[r+1]=obmen;
						}
					b[j]=a[i];
					break;
					}
				if (j+1==h)
				b[j+1]=a[i];
				}
				h++;
			}
			timer.End();
			cout << " | Затраченноевремя: " << fixed << setprecision(7) << timer.GetTime() << endl;
			cout << "\n";
		break;
		case 3:
			int min;
			obmen=0;
			cout << " ИЗВЛЕЧЕНИЕМ";
			timer.Start();
			for (int i = 0; i<n; i++){
				min=i;
				for (int j = i + 1; j<n; j++){
					if (a_izvl[j]<a_izvl[min]){
					min = j;
					}
				}
				obmen=a[i];
				a_izvl[i]=a_izvl[min];
				a_izvl[min]=obmen;
			}
			timer.End();
			cout << " | Затраченноевремя: " << fixed << setprecision(7) << timer.GetTime() << endl;
			cout << "\n";
		break;
		case 4:
			obmen=0;
			cout << " ОБМЕНОМ";
			timer.Start();
			for (int i = 0; i<n; i++) {
				for (int j = 0; j<n - i - 1; j++) {
					if (a_obmen[j] <a_obmen[j+1]) {
						obmen = a_obmen[j];
						a_obmen[j] = a_obmen[j+1];
						a_obmen[j+1] = obmen;
					}
				}
			}
			timer.End();
			cout << " | Затраченноевремя: " << fixed << setprecision(7) << timer.GetTime() << endl;
			cout << "\n";
		break;
		}		
	}
	}
	system("pause");
}