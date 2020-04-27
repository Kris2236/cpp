/* 2. Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę napisać
funkcję która odpowiada na pytanie, czy w każdym wierszu tablicy występuje co
najmniej jedna liczba złożona wyłącznie z nieparzystych cyfr. */

#include <iostream>

using namespace std;

void zero(int** tab, int max)
{
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			tab[i][j] = i*9 + j*2;
		}
	}
}

void wypisz(int** tab, int max)
{
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			cout << tab[i][j] << "\t";
			if ((j+1) % max == 0)
				cout << "\n";
		}
	}
}

bool el_np(int a)
{
	bool flag = false;
	while (a > 0 && !flag)
	{
		if (a % 2 == 0)
			flag = true;
		a=a/10;
	}
	if (flag == false)
		return 1;
	else
		return 0;
}

void check(int** tab, int max)
{
	bool flag = false;
	int counter=1;

	for (int i = 0; i < max; i++)
	{
		flag = false;
		for (int j = 0; j < max; j++)
		{
			if (tab[i][j] % 2 != 0)
			{
				flag = el_np(tab[i][j]);
				if (flag == 1)
				{
					cout << "W wierszu nr " << i << " istnieje element o niepazystych cyfrach: " << tab[i][j] << endl;
					break;
					break;
				}
			}
		}
	}
}

int main()
{
	int max=0;

    cout << "Podaj rozmiar tablicy: ";
	cin >> max;

	/*int ** tab = new int * [max];		//deklarowanie tablicy dynamicznej
	for (int i = 0; i < max; i++)
	{
		tab[i] = new int[max];
	}*/
	int tab[max][max];

	zero(tab, max);
	wypisz(tab, max);
	check(tab, max);

	/*for (int i = 0; i < max; i++)	//zwalnianie pamięci zarezerwowanej przez tablicę dynamiczną
	{
		delete [] tab[i];
	}
	delete[] tab;*/
	
	return 0;
}