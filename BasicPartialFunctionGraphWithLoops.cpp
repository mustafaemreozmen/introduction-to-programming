#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a, b, x;
	cout << "A: (A must be greater than B.)" << endl;
	cin >> a;
	cout << "B: (B must be less than A.)" << endl;
	cin >> b;
	system("@cls||clear");
	if (a > b)
	{
		for (int lineCount = 0; lineCount <= 5; lineCount++)
		{
			switch (lineCount)
			{
			case 1:
				cout << "graph of f(x) function: (* for defined scope, # for not-defined scope)" << endl;
				cout << "   "
					 << "|" << setw(b + 1) << b << setw((a - b) + 1) << a << endl;
				break;
			case 2:
				cout << setw(4);
				for (int markCount = 0; markCount < (3 * a); markCount++)
					cout << "-";
				cout << endl;
				break;
			case 3:
				cout << "   1" << setw(a + 1); //f(x) = 1 status.
				cout << "#";
				for (int asteriksOfOne = 0; asteriksOfOne <= (a); asteriksOfOne++)
					cout << "*";
				cout << endl;
				break;
			case 4:
				cout << "   0"; //f(x) = 0 status.
				cout << setw(b + 1);
				for (int asteriksOfZero = 0; asteriksOfZero <= ((a - b)); asteriksOfZero++)
					cout << "*";
				cout << endl;
				break;
			case 5:
				int asteriksOfMinusOne;
				cout << "  -1"; //f(x) = -1 status.
				for (asteriksOfMinusOne = 0; asteriksOfMinusOne <= (b - 1); asteriksOfMinusOne++)
					cout << "*";
				if (asteriksOfMinusOne = b)
					cout << "#";
				cout << endl;
				break;
			}
		}
	}
	else
	{
		cout << "There is an error in your A and B values." << endl;
		return -1;
	}
	system("PAUSE");
	return 0;
}
