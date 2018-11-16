#include <iostream>
using namespace std;

//Verilen sayıda karakter değerini yazan fonksiyonumuz.
void karakterYaz(char karakter, int sayi)
{
	for (int sutun = 0; sutun < sayi; sutun++) 
	{
		cout << karakter;
	}
}

//Verilen karakter sayısı kadar değeri yazdıktan sonra alt satıra geçen fonksiyonumuz.
void satirKarakterYaz(char karakter, int sayi)
{
	karakterYaz(karakter, sayi);
	cout << endl;
}

//Verilen karakter sayısı kadar * karakterini tüm satır için yazan fonksiyonumuz.
void satirYildizlari(int yildizsay)
{
	satirKarakterYaz('*', yildizsay);
}

//Verilen karakter sayısı kadar ' ' karakterini tüm satır için yazan fonksiyonumuz.

void satirBosluklari(int bosluksay)
{
	satirKarakterYaz(' ', bosluksay);
}

//'*', ' ', '*' karakterlerini yazan fonksiyonumuz.

void yildizBosYildiz(int bosluksay)
{
	cout << '*';
	karakterYaz(' ', bosluksay);
	cout << '*';
	cout << endl;
}

int main() 
{
	setlocale(LC_ALL, "Turkish");
	int uzunKenar = 24;
	int kisaKenar = 20;
	int ucgenSatir = 6;		// Üçgenlerin yıldızları kaç satır aşağının kaç satır aşağı ineceğini belirtiyoruz.

	int yildiz1 = 1;		//İlk üçgen ilk satırda 1 yıldız sonra 2'şer artacak.
	int yildiz2 = 3;		//Minik 2 satır ters üçgenin yıldızları 3 ve 2. satırda 1, her satırda 2 eksilecek.

	int bosluk = ucgenSatir - 1;		//6 satır üçgenin soldaki boşluk satır sayısı -1

	int bosluk3 = 0;
	int bosluk4 = 3;

	//İlk satırın yıldızları:
	satirYildizlari(uzunKenar);

	cout << "*SAU BILGISAYAR";
	for (int sauBosluk = 0; sauBosluk < 8; sauBosluk++)
		cout << " ";
		cout << "*";
		cout << endl;
	yildizBosYildiz(uzunKenar - 2);


	//Üst 2 dikdörtgen:
	for (int sat = 1; sat <= ucgenSatir; sat++)
	{
		//Her satir * ile başlar.
		cout << '*';

		//İlk üçgen tepe boşluğu:
		karakterYaz(' ', bosluk);

		//İlk üçgen yıldızları:
		karakterYaz('*', yildiz1);

		//İki üçgen arasındaki boşluk 2 katı:
		karakterYaz(' ', bosluk * 2);

		//İkinci üçgen birinci üçgen gibi aynı yıldız sayısı ile yazdırılabilir.
		karakterYaz('*', yildiz1);

		bosluk--;//Bu boşluklar her satırda bir azalıyor.
		yildiz1 += 2;	//Her iki üçgen de simetrik yıldızları her satırda iki artıyor.

						
		switch (sat) //İkinci üçgenin tepesi ile sonraki minik ters üçgenin tabanının ilk yıldızı arası 2 boşluk...
		{ 
			case 1:
			case 2:
				cout << "  ";
				karakterYaz('*', yildiz2);
				yildiz2 -= 2;
				karakterYaz(' ', bosluk3);
				bosluk3++;
			break;
			default:
				karakterYaz(' ', bosluk4);
				bosluk4--;
			break;
		}

		//Her satır yıldız ile başlar, enter ile biter.
		cout << '*';
		cout << endl;
	}

	yildizBosYildiz(uzunKenar - 2);
	cout << "*MUHENDISLIGI BOLUMU   *";
	cout << endl;
	yildizBosYildiz(uzunKenar - 2);

	//Değişkenleri ilk değerlerine alalım.
	yildiz1 = 1;//İlk üçgen ilk satırda 1 olarak tanımlandı.
	yildiz2 = 3;//Minik 2 satır ters üçgenin yıldızları 3 olarak tanımlandı.

	bosluk = ucgenSatir - 1; //Sol yandan her aşağı satıra inildiğinde 1'er boşluk çıkartacağız.

	bosluk3 = 0;
	bosluk4 = 3;

	for (int sat = 1; sat <= ucgenSatir; sat++)
	{
		//Her satır * ile başlar.
		cout << '*';

		//ilk üçgenin tepe boşluğu:
		karakterYaz(' ', bosluk);

		//ilk üçgenin yıldızları:
		karakterYaz('*', yildiz1);

		//İkinci üçgenin tepesi ile sonraki minik ters üçgenin tabanının ilk yıldızı arası 2 boşluğu yazdırma kısmı
		switch (sat) 
		{
			case 1:
			case 2:
			cout << "  ";
			
			karakterYaz('*', yildiz2);
			yildiz2 -= 2;
			
			karakterYaz(' ', bosluk3);
			bosluk3++;
			
			break;
		
			default:
			karakterYaz(' ', bosluk4);
			bosluk4--;
			
			break;
		}

		//iki üçgen arasındaki boşluk, ilk boşluk değişkenimizin 2 katı kadar olacak.
		karakterYaz(' ', bosluk);

		//İkinci üçgen, birinci üçgen gibi aynı yıldız sayısı ile yazdırılabilir.
		karakterYaz('*', yildiz1);

		karakterYaz(' ', bosluk);

		bosluk--; //Boşluklar her satırda birer tane azalıyor.
		yildiz1 += 2;	//Her iki üçgen de simetrik, yıldızlar her satırda ikişerli artıyor.

		//Her satır yıldız ve endl ile biter.
		cout << '*';
		cout << endl;
	}
		yildizBosYildiz(uzunKenar - 2);
		satirYildizlari(uzunKenar);
		system("PAUSE");
		return 0;
}
