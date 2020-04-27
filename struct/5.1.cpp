/* 4. Dana jest tablica ulamek t[100] zawierająca ciąg liczb wymiernych. Proszę napisać
funkcję, która policzy występujące w tablicy ciągi arytmetyczne (LA) i geometryczne (LG)
o długości większej niż 2. Funkcja powinna zwrócić wartość 1 gdy LA>LG, wartość -1 gdy
LA<LG oraz 0 gdy LA=LG. */

#include <iostream>
#include <math.h>

using namespace std;

struct ulamek {
	int l; // licznik – liczba całkowita
	int m; // mianownik – liczba większa od 0
}u1, u2, w;	//deklaracja zmiennych typu struct

void wspolny_mianownik(ulamek& a, ulamek& b)
{
	cout << "sprowadzanie do wspolnego mianownika..." << endl;
	if (b.m == a.m)
	{
		cout << "Mianownik ok" << endl;
	}
	else
	{
		a.l = a.l * b.m;
		a.m = a.m * b.m;
		b.l = b.l * a.m;
		b.m = b.m * a.m;
	}
}

ulamek skracanie(ulamek a)
{
	int tmp = a.l;
	cout << "skracanie..." << endl;

	for (int i = tmp; i >= 1; i--)
	{
		if (a.l % i == 0 && a.m % i == 0)
		{
			a.l = a.l / i;
			a.m = a.m / i;
		}
	}

	return a;
}

ulamek mnozenie(ulamek a, ulamek b)
{
	ulamek w;
	cout << "mnozenie..." << endl;
	w.l = a.l * b.l;
	w.m = a.m * b.m;

	w = skracanie(w);

	return w;
}

ulamek dzielenie(ulamek a, ulamek b)
{
	ulamek w;
	cout << "dzielenie..." << endl;
	w.l = a.l * b.m;
	w.m = a.m * b.l;

	w = skracanie(w);


	return w;
}

ulamek dodawanie(ulamek a, ulamek b)
{
	ulamek w;
	a = skracanie(a);
	b = skracanie(b);

	cout << "dodawanie..." << endl;
	wspolny_mianownik(a, b);

	w.l = a.l + b.l;
	w.m = a.m;

	w = skracanie(w);

	return w;
}

ulamek odejmowanie(ulamek a, ulamek b)
{
	ulamek w;
	a = skracanie(a);
	b = skracanie(b);

	cout << "odejmowanie..." << endl;
	wspolny_mianownik(a, b);

	w.l = a.l - b.l;
	w.m = a.m;

	w = skracanie(w);

	return w;
}

ulamek potegowanie(ulamek a)
{
	int n;
	cout << "potegowanie..." << endl << "Podaj potege:";	cin >> n;

	for (int i = 1; i < n; i++)
	{
		a.l = a.l * a.l;
		a.m = a.m * a.m;
	}

	return a;
}

void wpisz(ulamek &u1, ulamek &u2)
{
	cout << "Podaj licznik ulamka a: ";	cin >> u1.l;
	cout << "Podaj mianownik ulamka a: ";	cin >> u1.m;

	cout << "Podaj licznik ulamka b: ";	cin >> u2.l;
	cout << "Podaj mianownik ulamka b: ";	cin >> u2.m;
}

void wypisz(ulamek a)
{
	cout << a.l << endl << "-" << endl << a.m << endl;
}
	
int main()
{
	ulamek u1, u2, w;

	int t[100];
	for (int i = 0; i < 100; i++)
	{
		t[i] = rand
	}

	return 0;
}
