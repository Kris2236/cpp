/* 3. Na szachownicy o wymiarach 100x100 umieszczamy N hetmanów (N<100). Położenie hetmanów
jest opisywane przez strukturę dane:
struct hetman {
 int w; // wiersz 0..99
 int k; // kolumna 0..99
};
struct dane {
 hetman t[100]; // położenie hetmanów
 int N; // liczba hetmanów
};
Proszę napisać funkcję, która odpowiada na pytanie: czy żadne z dwa hetmany się nie
szachują? Do funkcji należy przekazać położenie hetmanów. */

#include <iostream>

using namespace std;

struct hetman {
	int w; // wiersz 0..99
	int k; // kolumna 0..99
};
struct dane {
	hetman t[100]; // położenie hetmanów - kolumna
	int N; // liczba hetmanów
};

void wpisz(dane& a)
{
	cout << "Podaj liczbe hetmanow:";
	cin >> a.N;
	for (int i = 1; i <= a.N; i++)
	{
		cout << "Podaj wiersz i kolumne hetmana" << i << endl;
		cin >> a.t[i].k;
		cin >> a.t[i].w;
	}
}

bool kolumna(dane a)
{
	for (int i = 1; i <= a.N; i++)
	{
		for (int j = 1; j <= a.N; j++)
		{
			if (a.t[i].k == a.t[j].k)
			{
				if(i != j)
					return 0;
			}
		}
	}
	return 1;
}

bool wiersz(dane a)
{
	for (int i = 1; i <= a.N; i++)
	{
		for (int j = 1; j <= a.N; j++)
		{
			if (a.t[i].w == a.t[j].w)
			{
				if (i != j)
					return 0;
			}
		}
	}
	return 1;
}

bool skos1(dane a)
{
	int counter=0;
	for (int i = 0; i <= 99; i++)
	{
		for (int j = 0; j <= 99; j++)
		{
			for (int k = 0; k <= 99 - k; k++)
			{
				if (k + i > 99)	break;
				cout << i << " ," << j << endl;
				if (a.t[j].w == (i) && a.t[j].k == (k + i))
				{
					counter++;

					if (counter == 2)
						return 1;
				}
			}
		}
		counter = 0;
	}
	return 0;
}

bool skos2(dane a)
{

	return 1;
}

int main()
{
	bool w, k, s1, s2;
	dane a;

	wpisz(a);

	k = kolumna(a);
	w = wiersz(a);
	s1 = skos1(a);

	cout << k << w << s1;
}
