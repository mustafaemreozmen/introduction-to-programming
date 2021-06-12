#include <iostream>
#include <conio.h>
#include <time.h>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	char keyPress;
	int choice = 1; 

	cout << "Enter array size:" << endl;
	cin >> n;
	int *numbers = new int[n]; 
	srand(time(NULL));			   
	for (int i = 0; i < n; i++)
		numbers[i] = rand() % 10;

	bool exit = false;
	while (!exit)
	{
		for (int i = 0; i < n; i++)
		{
			if (i == choice - 1)
				cout << "---> "; 
			else
				cout << setw(6);

			cout << numbers[i] << endl; 
		}

		cout << endl
			 << endl
			 << "a(A) up" << endl
			 << "d(D) down" << endl
			 << "c(C) exit";
		keyPress = _getch(); 
		switch (keyPress)	
		{
		case 'A':
		case 'a':
			choice--;
			break;
		case 'D':
		case 'd':
			choice++;
			break;
		case 'c':
		case 'C':
			return 0;
			break;
		default:
			break;
		}
		if (choice > n)
			choice = 1;
		else if (choice < 1)
			choice = n;

		system("@cls||clear");
	}

	delete numbers;
	return 0;
}
