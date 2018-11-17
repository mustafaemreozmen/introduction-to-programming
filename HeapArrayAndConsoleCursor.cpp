#include <iostream>
#include <conio.h>
#include <time.h>
#include <iomanip>
using namespace std;

int main()
{
	
	int n;
	char tus;
	int secim = 1; //Degisken atamalari yapildi.

	cout << "Lutfen diziniz icin boyut degerini giriniz." << endl;
	cin >> n;
	int* sayilar = new int[n]; //Dizi tanimlandi.
	srand(time(0)); //Random, time'a baglandi.
	for (int i = 0; i < n; i++)
		sayilar[i] = rand() % 10;  //Dongu ile dizi dolduruldu.
	
	bool cikis = false; 
	while (!cikis)
	{
		for (int i = 0; i < n; i++)
		{
			if (i == secim-1)
				cout << "---> "; //Imlec basildi.
			else
				cout << setw(6);

			cout << sayilar[i] << endl; //dizi basildi.
		}
		
	cout << endl << endl << "a(A) yukari gider" << endl << "d(D) asagi gider" << endl << "c(C) programi sonlandirir";
	tus = _getch();		//de�er girdisi alindi.
	switch (tus) //kontrol yapildi.
	{
		case 'A':
		case 'a':
		secim--;
		break;
		case 'D':
		case 'd':
		secim++;
		break;
		case 'c':
		case 'C':
		return 0;
		break;
		default:
		break;
	}
		if (secim > n) //n'inci terim sonrasi imlec basa dondu.
			secim = 1;

		else if (secim < 1) //1'inci terim oncesi imlec sona dondu.
			secim = n;

		system("@cls||clear"); //ekran basimlarda yenilendi.
	}
		
	delete sayilar;
	return 0;
}

