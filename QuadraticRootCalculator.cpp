#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double a, b, c, delta, x1, x2;
	cout << "Quadratic Equation Calculator" << endl << endl;
	cout << "(ax^2+bx+c) Enter the Coefficients" << endl;
	cout << "A:";
	cin >> a;
	cout << "B:";
	cin >> b;
	cout << "C:";
	cin >> c;

	delta = ((b * b) - (4 * a * c));

	if (delta > 0)
	{
		x1 = ((-b + sqrt(delta)) / (2 * a));
		x2 = ((-b - sqrt(delta)) / (2 * a));
		cout << "x1 value:" << setw(3) << x1 << endl;
		cout << "x2 value:" << setw(3) << x2 << endl;
	}
	else if (delta == 0)
	{
		x1 = ((-b) / (2 * a));
		x2 = x1;
		cout << "Roots are equal. Root:" << x1 << endl;
	}
	else
		cout << "Equation has no real root." << endl;
	system("PAUSE");
	return 0;
}
