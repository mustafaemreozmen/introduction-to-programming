#include <iostream>
using namespace std;

bool KontrolFonksiyonu(double sayi) //Sayi araligini kontrol eden boolean fonksiyonu.
{
	if (sayi < 0 || sayi > 100)
		return false;
	else
		return true;
}

void gecersizUyarisi() //Gecersiz araliktaki uyari mesaji fonksiyonu.
{
	cout << "Gecersiz deger." << endl;
	system("PAUSE");
}

int main()
{
	double birinciOdev;
	double ikinciOdev;
	double birinciKisaSinav;
	double ikinciKisaSinav;
	double notFinal;
	double notVize;
	double odevBirYuzde;
	double odevIkiYuzde;
	double vizeYuzde;
	double finalYuzde;
	double kisaSinavBirYuzde;
	double kisaSinavIkiYuzde;
	double toplamDersPuani;				//De�i�kenler tan�mland�


	cout << "Yilsonu Gecme Notunun Harf Karsiligini Bulan Program:" << endl << endl;
	cout << "Vize Notunuzu Giriniz:";
	cin >> notVize;
	if (KontrolFonksiyonu(notVize) != true)  //Bool cebri true d�nd���nde, hata verecek blok.
	{
		gecersizUyarisi();
		return 0;
	}	
	cout << "1.Odev Notunu Giriniz:";
	cin >> birinciOdev;
	if (KontrolFonksiyonu(birinciOdev) != true) //Bool cebri true d�nd���nde, hata verecek blok.
	{
		gecersizUyarisi();
		return 0;
	}	
	cout << "2.Odev Notunu Giriniz:";
	cin >> ikinciOdev;
	if (KontrolFonksiyonu(ikinciOdev) != true) //Bool cebri true d�nd���nde, hata verecek blok.
	{
		gecersizUyarisi();
		return 0;
	}	
	cout << "1.Kisa Sinav Notunu Giriniz:";
	cin >> birinciKisaSinav;
	if (KontrolFonksiyonu(birinciKisaSinav) != true) //Bool cebri true d�nd���nde, hata verecek blok.
	{
		gecersizUyarisi();
		return 0;
	}
	cout << "2.Kisa Sinav Notunu Giriniz:";
	cin >> ikinciKisaSinav;
	if (KontrolFonksiyonu(birinciKisaSinav) != true) //Bool cebri true d�nd���nde, hata verecek blok.
	{
		gecersizUyarisi();
		return 0;
	}	
	cout << "Final Notunu Giriniz:";
	cin >> notFinal;
	if (KontrolFonksiyonu(notFinal) != true) //Bool cebri true d�nd���nde, hata verecek blok.
	{
		gecersizUyarisi();
		return 0;
	}
	system("@cls||clear");
	cout << "Vizenin yil ici notunuza etkisi yuzde kactir?:";
	cin >> vizeYuzde;
	if (KontrolFonksiyonu(vizeYuzde) != true) //Bool cebri true dondugunde, hata verecek blok.
	{
		gecersizUyarisi();
		return 0;
	}
	vizeYuzde /= 100;	
	cout << "1. Odevin yil ici notunuza etkisi yuzde kactir?:";
	cin >> odevBirYuzde;
	if (KontrolFonksiyonu(odevBirYuzde) != true) //Bool cebri true dondugunde, hata verecek blok.
	{
		gecersizUyarisi();
		return 0;
	}
	odevBirYuzde /= 100;
	cout << "2. Odevin yil ici notunuza etkisi yuzde kactir?:";
	cin >> odevIkiYuzde;
	if (KontrolFonksiyonu(odevIkiYuzde) != true) //Bool cebri true dondugunde, hata verecek blok.
	{
		gecersizUyarisi();
		return 0;
	}
	odevIkiYuzde /= 100;
	cout << "1. Kisa sinavin yil ici notunuza etkisi yuzde kactir?:";
	cin >> kisaSinavBirYuzde;
	if (KontrolFonksiyonu(kisaSinavBirYuzde) != true) //Bool cebri true dondugunde, hata verecek blok.
	{
		gecersizUyarisi();
		return 0;
	}
	kisaSinavBirYuzde /= 100;
	cout << "2. Kisa sinavin yil ici notunuza etkisi yuzde kactir?:";
	cin >> kisaSinavIkiYuzde;
	if (KontrolFonksiyonu(kisaSinavIkiYuzde) != true) //Bool cebri true dondugunde, hata verecek blok.
	{
		gecersizUyarisi();
		return 0;
	}
	kisaSinavIkiYuzde /= 100;
	cout << "Finalin yil ici notunuza etkisi yuzde kactir?:";
	cin >> finalYuzde;
	if (KontrolFonksiyonu(finalYuzde) != true) //Bool cebri true dondugunde, hata verecek blok.
	{
		gecersizUyarisi();
		return 0;
	}
	finalYuzde /= 100;
	

	system("@cls||clear");
	cout << "Vizeden gelen puan�n�z:";
	notVize = (notVize * vizeYuzde); //Y�zde ile �arp�l�p ayn� de�i�kene atand�.
	cout << notVize << endl;
	cout << "�devlerden gelen puan�n�z:";
	birinciOdev = ((birinciOdev*odevBirYuzde)+(ikinciOdev*odevIkiYuzde));
	cout << birinciOdev << endl;
	cout << "K�sa S�navlardan gelen puan�n�z:";
	birinciKisaSinav = ((birinciKisaSinav*kisaSinavBirYuzde) + (ikinciKisaSinav*kisaSinavIkiYuzde));
	cout << birinciKisaSinav << endl;
	cout << "Finalden gelen puaniniz:";
	notFinal = (notFinal*finalYuzde);
	cout << notFinal << endl;
	cout << "Toplam ders notunuz:";
	toplamDersPuani = notFinal + birinciOdev + birinciKisaSinav + notVize;
	cout << toplamDersPuani << endl;

	if (toplamDersPuani <= 100 && toplamDersPuani >= 90) //Harf notu kontrolu yapildi.
		cout << "Gecme Notunuz AA." << endl;
	else if (toplamDersPuani <=89 && toplamDersPuani >= 85)
		cout << "Gecme Notunuz BA." << endl;
	else if (toplamDersPuani <= 84 && toplamDersPuani >= 80)
		cout << "Gecme Notunuz BB." << endl;
	else if (toplamDersPuani <= 79 && toplamDersPuani >= 75)
		cout << "Gecme Notunuz CB." << endl;
	else if (toplamDersPuani <= 74 && toplamDersPuani >= 65)
		cout << "Gecme Notunuz CC." << endl;
	else if (toplamDersPuani <= 64 && toplamDersPuani >= 58)
		cout << "Gecme Notunuz DC." << endl;
	else if (toplamDersPuani <= 57 && toplamDersPuani >= 50)
		cout << "Gecme Notunuz DD."<< endl;
	else
		cout << "Gecme Notunuz FF. Kald�n�z." << endl;
	
	system("PAUSE");
    return 0;
}

