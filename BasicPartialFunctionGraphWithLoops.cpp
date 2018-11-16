#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	{
		int a, b, x;
		

		cout << "Bir A degeri giriniz (Girdiginiz A degeri, birazdan gireceginiz B degerinden buyuk olmalidir. Esit deger girmeyiniz.)" << endl;
		cin >> a;
		cout << "Bir B degeri giriniz (Girdiginiz B degeri, az once girdiginiz A degerinden kucuk olmalidir. Esit deger girmeyiniz.)" << endl;
		cin >> b;
		system("@cls||clear");

		if (a > b) //A'nin B'den buyuk olmasi durumunda calisacak olan program bloguna giris.

			for (int satirSayisi = 0; satirSayisi <= 5; satirSayisi++) 
			{
				switch (satirSayisi) 
				{

					case 1:
						cout << "f(x) fonksiyonunun grafigi: (*'lar tanimli aralik, #'ler tanimsiz noktalardir.)" << endl << endl;
						cout << "   " << "|" << setw(b + 1) << b << setw((a - b) + 1) << a << endl; // Sekilsel tablo basimi gerceklesir.
					break;

					case 2:

						cout << setw(4);
						for (int cizgiSayisi = 0; cizgiSayisi < (3 * a); cizgiSayisi++) 
						{
							cout << "-"; // Sekilsel tablo basimi.
						}
					cout << endl;
					break;

				case 3:

					cout << "   1" << setw(a+1); //f(x)'in 1 oldugu araligin basildigi kesim.
					if (int yildizBir = 0);
					cout << "#";
					for (int yildizBir = 0; yildizBir <= (a); yildizBir++)
					{
						cout << "*";
					}
					cout << endl;
					break;

				case 4:
					cout << "   0"; //f(x)'in 0 oldugu araligin basildigi kisim.
					cout << setw(b+1);
					for (int yildizSifir = 0; yildizSifir <= ((a - b)); yildizSifir++)
					{
						cout << "*";
					}
					cout << endl;

					break;
					
				case 5:
					int yildizEksiBir;
					cout << "  -1"; //f(x)'in -1 oldugu araligin basildigi kisim.
					{
						for (yildizEksiBir = 0; yildizEksiBir <= (b-1); yildizEksiBir++)
					{
						cout << "*";
					}
						if (yildizEksiBir = b)
							cout << "#";
					
					cout << endl;

					break;
					}
				}
			}


		else //A, B'ye esit veyahut kucuk ise calisacak blok.
		{ 
			cout << "Girdiginiz degerlerde bir sorun var. Yeniden giriniz." << endl;
			system("PAUSE");
			return 0;
		}

		system("PAUSE");
		return 0;
	}
}



		

