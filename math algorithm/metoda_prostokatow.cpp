/* 10. Napisać program, który oblicza pole figury pod wykresem funkcji y=1/x w przedziale od 1 do k, metodą prostokątów. */

#include <iostream>
using namespace std;

long double f(long double x)
{
	x = 1 / x;
	return x;
}

int main()
{
	int k;
	bool koniec = false;
	long double y = 0, suma = 0, x = 0, d = 0;
	cout << "Podaj przedział 1 do k = ";					cin >> k;
	cout << "Podaj dokladnosc (1,2,... /jednostke x): ";	cin >> d;

	for (long double i = 0; i + 1 <= (k * d) && !koniec; i++)
	{
		x = (k - i/d);
		y = f(x);
		if (x <= 1)		koniec = true;
		suma += y*1/d;
		cout << "y = " << y << endl;
	}

	cout << suma << endl;
}