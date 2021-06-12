#include <iostream>
using namespace std;

void characterPrint(char karakter, int sayi)
{
	for (int sutun = 0; sutun < sayi; sutun++)
	{
		cout << karakter;
	}
}

void lineCharacterPrint(char karakter, int sayi)
{
	characterPrint(karakter, sayi);
	cout << endl;
}

//Verilen karakter sayısı kadar * karakterini tüm satır için yazan fonksiyonumuz.
void lineAsteriks(int yildizsay)
{
	lineCharacterPrint('*', yildizsay);
}

//Verilen karakter sayısı kadar ' ' karakterini tüm satır için yazan fonksiyonumuz.

void lineSpaces(int spacesay)
{
	lineCharacterPrint(' ', spacesay);
}

//'*', ' ', '*' karakterlerini yazan fonksiyonumuz.

void asteriksSpaceAsteriks(int spacesay)
{
	cout << '*';
	characterPrint(' ', spacesay);
	cout << '*';
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	int longSide = 24;
	int shortSide = 20;
	int triangleLine = 6; // Üçgenlerin yıldızları kaç satır aşağının kaç satır aşağı ineceğini belirtiyoruz.

	int asteriksOne = 1; //İlk üçgen ilk satırda 1 yıldız sonra 2'şer artacak.
	int asteriksTwo = 3; //Minik 2 satır ters üçgenin yıldızları 3 ve 2. satırda 1, her satırda 2 eksilecek.

	int space = triangleLine - 1; //6 satır üçgenin soldaki boşluk satır sayısı -1

	int spaceThree = 0;
	int spaceFour = 3;

	//İlk satırın yıldızları:
	lineAsteriks(longSide);

	cout << "*SAU COMPUTER";
	for (int sauSpace = 0; sauSpace < 8; sauSpace++)
		cout << " ";
	cout << "*";
	cout << endl;
	asteriksSpaceAsteriks(longSide - 2);

	//Üst 2 dikdörtgen:
	for (int sat = 1; sat <= triangleLine; sat++)
	{
		cout << '*';
		characterPrint(' ', space);
		characterPrint('*', asteriksOne);
		characterPrint(' ', space * 2);
		characterPrint('*', asteriksOne);
		space--;	
		asteriksOne += 2; 

		switch (sat) 
		{
		case 1:
		case 2:
			cout << "  ";
			characterPrint('*', asteriksTwo);
			asteriksTwo -= 2;
			characterPrint(' ', spaceThree);
			spaceThree++;
			break;
		default:
			characterPrint(' ', spaceFour);
			spaceFour--;
			break;
		}
		cout << '*';
		cout << endl;
	}

	asteriksSpaceAsteriks(longSide - 2);
	cout << "*ENGINEERING          *";
	cout << endl;
	asteriksSpaceAsteriks(longSide - 2);

	asteriksOne = 1; 
	asteriksTwo = 3; 

	space = triangleLine - 1; 

	spaceThree = 0;
	spaceFour = 3;

	for (int sat = 1; sat <= triangleLine; sat++)
	{
		cout << '*';
		characterPrint(' ', space);
		characterPrint('*', asteriksOne);
		switch (sat)
		{
		case 1:
		case 2:
			cout << "  ";
			characterPrint('*', asteriksTwo);
			asteriksTwo -= 2;
			characterPrint(' ', spaceThree);
			spaceThree++;
			break;
		default:
			characterPrint(' ', spaceFour);
			spaceFour--;
			break;
		}

		characterPrint(' ', space);
		characterPrint('*', asteriksOne);
		characterPrint(' ', space);
		space--;	 
		asteriksOne += 2; 
		cout << '*';
		cout << endl;
	}
	asteriksSpaceAsteriks(longSide - 2);
	lineAsteriks(longSide);
	system("PAUSE");
	return 0;
}
