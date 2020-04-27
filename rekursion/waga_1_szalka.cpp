/* Dany jest zestaw odważników int t[N]. Napisać funkcję, która sprawdza czy jest
możliwe odważenie określonej masy. Odważniki można umieszczać tylko na jednej szalce. */

#include <iostream>

using namespace std;
const int n = 7;

void wypisz(int t[n], bool mapa[n])
{
	for (int i = 0; i < n; i++)
		cout << mapa[i] << "\t" << t[i] << endl;
	cout << endl;
}

void wynik(bool flag)
{
	if (flag == true)	cout << "TAK" << endl;
	else				cout << "NIE";
}

bool waga(int* t, bool mapa[n], int n, int x, int p, bool& koniec)				//t- tablica odważników;	n	-	rozmiar tablicy z odważnikami;	x	-	masa do odważenia;	p	-	aktualna pozycja;
{
	if (x - t[p] == 0 || koniec)							//warunek zerowy TRUE, koniec zakańcza dalsze sprawdzanie
	{ 
		if (!koniec)
		{
			mapa[p] = 1;
			wypisz(t, mapa);
		}
		koniec = true;
		return true;
	}							
	else if (p == n || x - t[p] < 0)						//warunek zerowy false
	{
		return false;			
	}
	//cout << "p = " << p << " Odwaznik = " << t[p] << " \t x - t[p] = " << x - t[p] << endl;
	mapa[p] = 1;
	waga(t, mapa, n, x - t[p], p + 1, koniec);					//spr kolejny odważnik
	mapa[p] = 0;
	waga(t, mapa, n, x, p + 1, koniec);							//pomija aktualny odważnik
}

int main()
{
	bool flag = false;
	int x;
	int t[n] = {1,3,5,8,16,20,40};							//	tab z masą odważników
	bool mapa[n] = {0,0,0,0,0,0,0};							//	tab pomocnicza, pokazująca które odważniki zostały użyte
	cout << "Podaj mase do odwazenia: ";	cin >> x;

	flag = waga(t, mapa, n, x, 0, flag);							//	(	...	zaczynamy od pozycji 0(p);	zaczynamy z wart koniec = false)
	wynik(flag);
}

// dynamiczne tworzenie tablicy
// int *t = new int [n];
// ...
// delete[] t;