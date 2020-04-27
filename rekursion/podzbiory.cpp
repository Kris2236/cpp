/*„Waga” liczby jest określona jako ilość różnych czynników pierwszych liczby. Na przykład waga(1)=0, waga(2)=1, waga(6)=2, waga(30)=3, waga(64)=1. Dana jest
tablica: int t[N]. Tablica zawiera liczby naturalne. Proszę napisać funkcję, która sprawdza czy można elementy tablicy podzielić na 3 podzbiory o równych wagach. Do
funkcji należy przekazać wyłącznie tablicę, funkcja powinna zwrócić wartość typu bool.*/

#include <iostream>
using namespace std;
const int m = 7;

int policz_wagi(int a)
{
	int n = 2;
	int counter = 0;
	int tmp;

	while (n <= a)
	{
		tmp = a;
		while (a % n == 0)			//spr czy liczba jest podzielna przez l. pierwszą
		{
			a = a / n;				//dzieli przez liczbę pierwszą
		}
		n++;
		if (a != tmp)	counter++;	//jeśli liczba została podzielona maxylmalną ilość razy przez l. pierwszą dodajemy wagę
	}
	//cout << counter << endl;
	return counter;
}

void wypisz(int t[m])
{
	for (int i = 0; i < m; i++)
	{
		cout << t[i] << ",  ";
	}
	cout << endl;
}
//			tablica		|	trzy pozdbiory	 | pozycja|	zakańcza wykonywanie funkcji
bool podziel(int waga[m], int a, int b, int c, int n)		//funkcja rekurencyjie wyszukująca 3 podzbiorów
{
	cout << n << "| " << a << ", " << b << ", " << c << ", " << endl;
	if (a == b && b == c && n == m)							//warunek zerowy true
		return true;
	else if(n == m)											// warunek zerowy false
		return false;

	return	podziel(waga, a +waga[n], b, c, n + 1)||
			podziel(waga, a, b +waga[n], c, n + 1)||
			podziel(waga, a, b, c +waga[n], n + 1);
}

int dodaj_wagi(int waga[m])
{
	int suma = 0;
	for (int i = 0; i < m ;i++)
	{
		suma = suma + waga[i];
	}
	return suma;
}

bool sprawdz(int t[m])
{
	int waga[m] = { 0 };
	for (int i = 0; i < m; i++)
	{
		waga[i] = policz_wagi(t[i]);
	}
	wypisz(waga);
	if (dodaj_wagi(waga) % 3 != 0)								// jeśli suma wag jest liczbą niepodzielną przez 3 to nie da się podzielić na 3 podzbiory
		return 0;
	cout << "Wagi podzielne przez 3" << endl;

	if (podziel(waga, 0, 0, 0, 0) == 1)	return 1;				//funkcja sprawdza czy da się podzielić wagi na3 zbiory o takiej samej sumie wag
	else return 0;
}

int main()
{
	int t[m] = {1,2,3,4,64,8,9};

	if (sprawdz(t))		cout << "TAK";
	else				cout << "NIE";

}