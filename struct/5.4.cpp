/* Dana jest tablica ulamek t[100] zawierająca ciąg liczb wymiernych. Proszę napisać
funkcję, która policzy występujące w tablicy ciągi arytmetyczne (LA) i geometryczne (LG)
o długości większej niż 2. Funkcja powinna zwrócić wartość 1 gdy LA>LG, wartość -1 gdy
LA<LG oraz 0 gdy LA=LG. */

#include <iostream>

using namespace std;
const int N = 100;

void wpisz(int t[N])
{
	for (int i = 0; i < N; i++)
	{
		t[i] = rand() % 20 + 1;
		cout << t[i] << "\t";
		if (i % 10 == 0)	cout << endl;
	}
}

void arytm(int t[N])
{
	int r, maxdlugosc = 0, dlugosc = 0, k = 0, ilosc=0;
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		flag = false;
		r = t[i + 1] - t[i];	//róznica w ciagu
		cout << t[i] << ", " << t[i + 1] << ", ";

		for (int k=0; i+k+2 < N && !flag; k++)
		{
			if (t[i + k+2] - t[i + k+1] == r)	//jesli kolejne wyrazy majaą tą samą róznice to zwiększamy długość
			{
				dlugosc++;
				cout << t[i + k + 2] << ", [" << i+k+2 << "], ";
			}
			if((t[i + k + 2] - t[i + k + 1] != r) || (i + k + 3 == N))
			{
				cout << endl << "DLUGOSC = " << dlugosc << endl;
				if (maxdlugosc < dlugosc)
					maxdlugosc = dlugosc;
				if (dlugosc != 0)
				{
					ilosc++;
					dlugosc = 0;
				}

				flag = true;
			}
		}
	}
	cout << "MAX dlugosc ciagu arytm :" << maxdlugosc << endl;
	cout << "ilosc ciagow arytm :" << ilosc << endl;
}

void geom(int t[N])
{
	int maxdlugosc = 0, dlugosc = 0, k = 0, ilosc = 0;
	double q=0;
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		flag = false;
		q = (double)t[i + 1] /t[i];	//iloraz w ciagu
		cout << t[i] << ", " << t[i + 1] << ", ";

		for (int k = 0; i + k + 2 < N && !flag; k++)
		{
			if ((double)t[i + k + 2]/ t[i + k + 1] == q)	//jesli kolejne wyrazy majaą tą samą róznice to zwiększamy długość
			{
				dlugosc++;
				cout << t[i + k + 2] << ", [" << i + k + 2 << "], ";
			}
			if ((double)(t[i + k + 2] / t[i + k + 1] != q) || (i + k + 3 == N))
			{
				cout << endl << "DLUGOSC = " << dlugosc << endl;
				if (maxdlugosc < dlugosc)
					maxdlugosc = dlugosc;
				if (dlugosc != 0)
				{
					ilosc++;
					dlugosc = 0;
				}

				flag = true;
			}
		}
	}
	cout << "MAX dlugosc ciagu geom :" << maxdlugosc << endl;
	cout << "ilosc ciagow geom :" << ilosc << endl;
}

int main()
{
	int t[N];
	//int t[N] = {1,2,4,8,1,2};
	wpisz(t);
	arytm(t);
	geom(t);
}