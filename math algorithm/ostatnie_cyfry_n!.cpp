/* Napisać program, który wyznacza ostatnia niezerową cyfra N! Program powinien
działać dla N rzędu 1000000. */

#include <iostream>

using namespace std;

unsigned long long int podaj_cyfre(unsigned long long int n)
{
	while (n % 10 == 0)
	{
		n = n / 10;
	}
	while (n > 1000)
	{
		n = n - 1000;
	}
	while (n > 100)
	{
		n = n - 100;
	}

	return n;
}

unsigned long long int silnia(unsigned long long int n)
{
	unsigned long long int j = n;
	while (j > 1)
	{
		j--;
		n = n * j;
		n = podaj_cyfre(n);
	}

	while (n > 10)
	{
		n = n - 10;
	}

	return n;
}


int main()
{
	unsigned long long int n = 0;

	cout << "Podaj liczbe: ";
	cin >> n;

	n = silnia(n);
	cout << "Wynik = " << n << endl;

	return 0;
}
