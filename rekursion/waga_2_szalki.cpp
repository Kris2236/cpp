/* Dany jest zestaw odważników int t[N]. Napisać funkcję, która sprawdza czy jest
możliwe odważenie określonej masy. Odważniki można umieszczać na obu szalkach.  */

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

bool sprawdz(bool mapa[n], int p)								//funkcja spr czy szalka jest używana
{
	if (mapa[p] == 0)	return true;							//szalka jest wolna
	else				return false;							//szalka jest w użyciu
}

bool waga(int* t, bool mapa[n], bool mapa_l[n], bool mapa_p[n], int n, int x, int p, bool& koniec)	//t- tablica odważników;	n	-	rozmiar tablicy z odważnikami;	x	-	masa do odważenia;	p	-	aktualna pozycja;
{
	//cout << x << endl << t[p] << endl << endl;
	if (x - t[p] == 0 || koniec)								//warunek zerowy TRUE, koniec zakańcza dalsze sprawdzanie
	{
		if (!koniec)
		{
			mapa[p] = 1;
			mapa_l[p] = 1;
			//mapa_p[p] = 1;
			cout << "Uzyte odwazniki:" << endl;
			wypisz(t, mapa);
			cout << "Uzyte odwazniki LEWA:" << endl;
			wypisz(t, mapa_l);
			cout << "Uzyte odwazniki PRAWA (masa do odwazenia):" << endl;
			wypisz(t, mapa_p);
			cout << x << " = " << t[p] << endl << endl;
		}
		koniec = true;
		return true;
	}
	else if (p == n || x - t[p] < 0)							//warunek zerowy false
	{
		return false;
	}
	mapa[p] = 1;
	mapa_l[p] = 1;
	waga(t, mapa, mapa_l, mapa_p, n, x - t[p], p + 1, koniec);					//dodaje odważnika na szalkę po lewej
	mapa[p] = 0;
	mapa_l[p] = 0;
	waga(t, mapa, mapa_l, mapa_p, n, x, p + 1, koniec);							//pomija aktualny odważnik dla szalki po lewej
	if (sprawdz)
	{
		mapa[p] = 1;											//włożenie szalki na wagę
		mapa_p[p] = 1;
		waga(t, mapa, mapa_l, mapa_p, n, x + t[p], p + 1, koniec);							//dodaje odważnik na szalkę po prawej
	}
	if (sprawdz)
	{
		mapa[p] = 0;												//zwrócenie szalki do puli
		mapa_p[p] = 0;
		waga(t, mapa, mapa_l, mapa_p, n, x, p + 1, koniec);							//pomija aktualny odważnik dla szalki po prawej
	}
}

int main()
{
	bool flag = false;
	int x;
	int t[n] = { 1,3,5,8,16,20,40 };							//	tab z masą odważników
	bool mapa[n] = { 0,0,0,0,0,0,0 };							//	tab pomocnicza, pokazująca które odważniki zostały użyte
	bool mapa_l[n] = { 0,0,0,0,0,0,0 };							//	tab pomocnicza, pokazująca które odważniki zostały użyte
	bool mapa_p[n] = { 0,0,0,0,0,0,0 };							//	tab pomocnicza, pokazująca które odważniki zostały użyte
	cout << "Podaj mase do odwazenia: ";	cin >> x;

	flag = waga(t, mapa, mapa_l, mapa_p, n, x, 0, flag);						//	(	...	zaczynamy od pozycji 0(p);	zaczynamy z wart koniec = false)
	wynik(flag);
}
