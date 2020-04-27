/*	7. Dana jest tablica int t[N]. Proszę napisać funkcję, która znajdzie niepusty, najmniejszy (w sensie liczebności) podzbiór elementów tablicy, dla którego suma
elementów jest równa sumie indeksów tych elementów. Do funkcji należy przekazać tablicę, funkcja powinna zwrócić sumę elementów znalezionego podzbioru. Na przykład
dla tablicy: [ 1, 7, 3, 5, 11, 2 ] rozwiązaniem jest liczba 10.		REKURENCJA		*/

#include <iostream>
using namespace std;
const int N = 6;

void podzbior(int t[N], string kombinacja, int n, bool& koniec)
{
	if (n == N && !koniec)			//warunek ZERO
	{
		int sumaEl = 0;
		int sumaIdx = 0;

		for (int i = 0; i < N && !koniec; i++)
		{
			if (kombinacja[i] == '1')
			{
				sumaEl += t[i];
				sumaIdx += i;
			}
		}
		cout << kombinacja << endl << sumaEl << endl << sumaIdx << endl << endl;

		if (sumaIdx == sumaEl && sumaIdx != 0)
		{
			koniec = true;
			cout << "KONIEC" << endl;
		}
	}
	else if( !koniec )
	{
		podzbior(t, kombinacja + '0', n + 1, koniec);		//pomijamy n-ty element
		podzbior(t, kombinacja + '1', n + 1, koniec);		//idziemy dalej w ciągu
	}
}

int main()
{
	bool koniec = false;
	int t[N] = { 1,7,3,5,11,2 };

	podzbior(t, "", 0, koniec);		//(tab, mapa, n(pozycja), suma elementów, suma indeksów, flaga zakańczająca pętle)
}