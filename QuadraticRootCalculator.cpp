#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double a, b, c, delta, x1, x2; //de�i�kenler tan�mland�.
	cout << "Ikinci Dereceden Denklemin Koklerini Bulan Program" << endl << endl;
	cout << "(ax^2+bx+c) denkleminin katsayilarini giriniz." << endl;
	cout << "a degeri:";
	cin >> a;
	cout << "b degeri:";
	cin >> b;
	cout << "c degeri:";
	cin >> c;

	delta = ((b*b) - (4 * a*c)); //delta hesapland�.

	if (delta > 0) //delta 0'dan b�y�kse durumu kontrol edildi.
	{
		x1 = ((-b + sqrt(delta)) / (2 * a));
		x2 = ((-b - sqrt(delta)) / (2 * a));
		cout << "x1 degeriniz:" << setw(3) << x1 << endl;
		cout << "x2 degeriniz:" << setw(3) << x2 << endl;
	}

	else if (delta == 0) //delta s�f�ra denkse durumu kontrol edildi.
	{
		x1 = ((-b) / (2 * a));
		x2 = x1;
		cout << "Kokler birbirine esittir. Kok:" << x1 << endl;
	}

	else
		cout << "Denkleminizin reel koku bulunmamaktad�r." << endl; //iki durum da uymuyorsa reel de�ildir.
	
	
	system("PAUSE");
    return 0;
}

