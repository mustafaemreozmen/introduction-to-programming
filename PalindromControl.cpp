#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


struct KelimeOzellik
{
	//string noktalamalar;
	string harfler;
	int harfSayisi;
	string sesliHarfler;
	bool palindromMu;
};
//Kelimeye dair özellikleri tutan struct.


struct CumleOzellik
{
	string noktalamalar;
	string girilenCumle;
	int kelimeSayisi;
	KelimeOzellik kelimeler[255];
	int harfSayisi;
	int kelimeSesliHarfSayilari;
	int palindromKelimeSayisi;
	bool palindromMu;
};
//Cümleye dair özellikleri tutan struct.

CumleOzellik cumle;

bool NoktalamaKarakteriMi(char harf);
bool SesliKarakterMi(char harf);
bool CumlePalindromMu(string cumle);
KelimeOzellik KelimeOzellikKontrolu(KelimeOzellik kelime);
void StructKontrolu();

int main()
{
	setlocale(LC_ALL, "Turkish");

	cout << "Lütfen bir cümle giriniz.(Türkçe karakter kullanmayınız.)" << endl;
	getline(cin, cumle.girilenCumle);

	for (int i = 0; i<cumle.girilenCumle[i]; i++)
		cumle.girilenCumle[i] = tolower(cumle.girilenCumle[i]);
	StructKontrolu();

	system("@cls ||clear");

	cout << "Girdiğiniz Cümle:.........................................: " << cumle.girilenCumle << endl;
	cout << "Cümledeki kelime sayısı nedir?............................: " << cumle.kelimeSayisi << endl;
	cout << "Cümlenin Harf Sayısı nedir?...............................: " << cumle.harfSayisi << endl;
	cout << "Cümledeki noktalama işaretleri nelerdir?..................: " << cumle.noktalamalar << endl;
	cout << "Cümle palindrom(okunuşu ile tersten okunuşu aynı) mu?.....: ";

	if (cumle.palindromMu == 1)
		cout << "Evet, palindrom" << endl; //Ekrana bool'un durumuna göre çıktı veriyor.
	else if (cumle.palindromMu == 0)
		cout << "Hayır, değil." << endl;

	cout << "Cümlede Palindrom Kelime Var Mı?..........................: " << cumle.palindromKelimeSayisi << "\n";

	for (int i = 0; i < cumle.kelimeSayisi; i++)
	{
		if (cumle.kelimeler[i].palindromMu)
			cout << cumle.kelimeler[i].harfler << "\n";
	}
	cout << "\nCümledeki kelimelerin harf sayıları nedir?................:\n\n";

	for (int i = 0; i < cumle.kelimeSayisi; i++)
	{
		cout << cumle.kelimeler[i].harfler << " kelimesinin harf sayısı.:";
		cout << cumle.kelimeler[i].harfSayisi;
		cout << endl;
	}

	cout << "\n\nCümledeki kelimelerin sesli harf sayıları nedir?..........: \n\n";

	for (int i = 0; i < cumle.kelimeSayisi; i++)
	{
		cout << cumle.kelimeler[i].harfler << " kelimesinin sesli harf sayısı.:" << cumle.kelimeler[i].sesliHarfler.length() << "\n";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}

bool NoktalamaKarakteriMi(char harf) //Noktalama karakteri olup olmadığını kontrol eden bool fonksiyonu.
{
	switch (harf)
	{
	case '.':
	case ':':
	case ',':
	case ';':
	case '-':
	case '\'':
	case '\"':
	case '_':
	case '?':
	case '^':
	case '!':
		return true;
		break;
	default:
		break;
	}

	return false;
}

bool SesliKarakterMi(char harf) //Sesli karakter olup olmadığını kontrol eden bool fonksiyonu
{
	switch (harf)
	{
	case 'a':
	case 'A':
	case 'e':
	case 'E':
	case 'i':
	case 'İ':
	case 'ı':
	case 'I':
	case 'o':
	case 'O':
	case 'ö':
	case 'Ö':
	case 'u':
	case 'U':
	case 'ü':
	case 'Ü':
		return true;
		break;
	default:
		break;
	}

	return false;
}

bool CumlePalindromMu(string cumle) //Cumlenin palindrom olup olmadığını, boşluk ve noktalamaları gözetmeden kontrol eden bool fonksiyonu.
{
	bool donus = true;

	string gecici = "";
	for (int i = 0; i < cumle.length(); i++) //Uzunluğuna kadar dönüp, noktalama durumunu kontrol ediyor.
	{
		if (cumle[i] != ' ' && cumle[i] != '.' && cumle[i] != ',' && cumle[i] != ';' && cumle[i] != ':' && cumle[i] != '?' && cumle[i] != '!' && cumle[i] != '\'' && cumle[i] != '-' && cumle[i] != '_')
			gecici.append(1, cumle[i]);
	}

	int uzunluk = gecici.length();
	for (int i = 0; i < uzunluk; i++) //Dönüp cümlenin palindromluğunu kontrol ediyor.
	{
		if (gecici[i] != gecici[uzunluk - i - 1])
		{
			donus = false;
			break;
		}
	}
	return donus;
}

KelimeOzellik KelimeOzellikKontrolu(KelimeOzellik kelime) //Kelimelere dair palindromluluk ve sesli harflilik durumunu kontrol eden fonksiyon.
{
	bool palindrom = true;
	kelime.harfSayisi = kelime.harfler.length();
	for (int i = 0; i < kelime.harfSayisi; i++)
	{
		char ch = kelime.harfler[i];
		if (ch != kelime.harfler[kelime.harfSayisi - i - 1])
		{
			palindrom = false;
		}
		palindrom = palindrom & true;



		if (SesliKarakterMi(ch))
			kelime.sesliHarfler.append(1, ch);
	}
	kelime.palindromMu = palindrom;
	return kelime;
}

void StructKontrolu() 	//Kelimelerin kontrolü burada 

{
	int kelimeSayisi = 0;
	int sonIndis = -1;
	for (int i = 0; i < cumle.girilenCumle.length(); i++) //Kelime atamaları yapılıyor.
	{
		if (cumle.girilenCumle[i] == ' ' || cumle.girilenCumle[i] == '.' || cumle.girilenCumle[i] == ',' || cumle.girilenCumle[i] == ';' || cumle.girilenCumle[i] == ':' || cumle.girilenCumle[i] == '?' || cumle.girilenCumle[i] == '!' || cumle.girilenCumle[i] == '\'' || cumle.girilenCumle[i] == '-' || cumle.girilenCumle[i] == '_')
		{
			KelimeOzellik kelime;
			kelime.harfler = cumle.girilenCumle.substr(sonIndis + 1, i - sonIndis - 1);
			kelime = KelimeOzellikKontrolu(kelime);
			cumle.kelimeler[kelimeSayisi] = kelime;
			sonIndis = i;
			kelimeSayisi++;
		}
	}
	if (cumle.girilenCumle.substr(sonIndis + 1).length() > 1)
	{
		KelimeOzellik kelime;
		kelime.harfler = cumle.girilenCumle.substr(sonIndis + 1);
		kelime = KelimeOzellikKontrolu(kelime);
		cumle.kelimeler[kelimeSayisi] = kelime;
		kelimeSayisi++;
	}

	cumle.kelimeSayisi = kelimeSayisi;
	cumle.palindromMu = CumlePalindromMu(cumle.girilenCumle);

	cumle.kelimeSesliHarfSayilari = 0;
	cumle.harfSayisi = 0;
	cumle.palindromKelimeSayisi = 0;
	cumle.noktalamalar = "";
	for (int i = 0; i < cumle.kelimeSayisi; i++) //Kelimenin palindrom kelime olup olmadığına göre sayı arttırılıyor
	{
		cumle.kelimeSesliHarfSayilari += cumle.kelimeler[i].sesliHarfler.length();
		cumle.harfSayisi += cumle.kelimeler[i].harfSayisi;
		if (cumle.kelimeler[i].palindromMu)
			cumle.palindromKelimeSayisi++;
	}

	for (int i = 0; i < cumle.girilenCumle.length(); i++) //Noktalamalar atanıyor
	{
		char ch = cumle.girilenCumle[i];
		if (NoktalamaKarakteriMi(ch))
			cumle.noktalamalar.append(1, ch);
	}
}
