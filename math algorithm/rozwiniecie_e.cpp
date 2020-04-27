/*		5. Obliczanie stałej e z rozwinięcia w szereg e=1/0!+1/1!+1/2!+1/3!+... z dokładnością do np. 1000 cyfr dziesiętnych.		*/

#include <iostream>

using namespace std;

long double silnia(long double h)
{
	long long int j = h;
	while (j > 1)
	{
		j--;
		h = h * j;
		cout << "n! " << h << endl;
	}
	return h;
}

long double fn(long double n)
{
	long double e = 1.0;
	for (int i = 1; i < n+1; i++)
	{
		e = e + (1/silnia(i));
		cout << "e " << e << endl;
	}
	return e;
}

int main()
{
	long double n;

	cout << "Podaj dokloadnosc: ";
	cin >> n;

	n = fn(n);
	cout << n;
}