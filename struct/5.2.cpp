﻿/* 1. Liczby wymierne są reprezentowane przez strukturę:
struct ulamek {
 int l; // licznik – liczba całkowita
 int m; // mianownik – liczba większa od 0
};
Proszę napisać podstawowe operacje na ułamkach, m.in. dodawanie, odejmowanie, mnożenie,
dzielenie, potęgowanie, skracanie, wypisywanie i wczytywanie. */

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

void wpisz(ulamek& u1, ulamek& u2)
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
	/*
	wpisz(u1, u2);
	
	w = mnozenie(u1, u2);
	wypisz(w);

	w = dzielenie(u1, u2);
	wypisz(w);

	w = potegowanie(u1);
	wypisz(w);

	w = potegowanie(u2);
	wypisz(w);

	w = dodawanie(u1, u2);
	wypisz(w);

	w = odejmowanie(u1, u2);
	wypisz(w);
	*/


	ulamek a1, b1, c1, a2, b2, c2, w, w2;

	cout << "Uklad rownan:" << endl;
	cout << "x";						cin >> a1.l;
	cout << a1.l << "x + y";				cin >> b1.l;
	cout << a1.l << "x + " << b1.l << "y = ";	cin >> c1.l;

	cout << "x";							cin >> a2.l;
	cout << a2.l << "x + y";					cin >> b2.l;
	cout << a2.l << "x + " << b2.l << "y = ";	cin >> c2.l;

	a1.m = 1; a2.m = 1; b1.m = 1; b2.m = 1; c1.m = 1; c2.m = 1;

	//	x
	w = mnozenie(b2, c1);
	w = dzielenie(w, b1);
	w = odejmowanie(c2, w);

	w2 = mnozenie(b2, a1);
	w2 = dzielenie(w2, b1);
	w2 = odejmowanie(a2, w2);

	w = dzielenie(w, w2);
	wypisz(w);

	// y
	w2 = mnozenie(a1, w);
	wypisz(w2);
	//	napraw odejmowanie liczb ujemnych
	w2 = odejmowanie(c1, w2);
	wypisz(c1);
	wypisz(w2);
	w2 = dzielenie(w2, b2);
	wypisz(w2);

	return 0;
}


