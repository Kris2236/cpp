/* Pewnych liczb nie można przedstawić jako sumy elementów spójnych fragmentów ciągu
Fibonacciego, np. 9,14,15,17,22. Proszę napisać program, który wczytuje liczbę
naturalną n, wylicza i wypisuje następną taką liczbę większą od n. Można założyć,
że 0<n<1000. */

#include <iostream>

using namespace std;

int fibbonaci(int a)
{
	int a1 = a;
	static int a2 = 0;

	if (a == 0)
		return 0;

	else if (a >= 1)
	{
		a1 = a1 + a2;
		a2 = a1 - a2;
	}

	return a1;
}

int fibbonaci2(int a)
{
	int a12 = a;
	static int a22 = 0;

	if (a == 0)
		return 0;

	else if (a >= 1)
	{
		a12 = a12 + a22;
		a22 = a12 - a22;
	}

	return a12;
}

int main()
{
	int n;
	int fib = 1;
	bool result = false;

	cout << "Podaj liczbe: ";
	cin >> n;

	while (1000 > fib && !result)
	{
		fib = fibbonaci2(fib);
		//cout << fib << endl;

		if (fib == n)
			result = true;
	}

	if (result == true)
	{
		n++;
		cout << n << endl;
	}
	else
	{
		n++;
		fib = 1;
		while (1000 > fib && !result)
		{
			fib = fibbonaci(fib);
			//cout << fib << endl;

			if (fib == n)
				n++;
		}

		cout << n;
	}
}
