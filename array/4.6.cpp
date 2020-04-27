/*6. Dane są dwie tablice mogące pomieścić taką samą liczbę elementów:
int t1[MAX][MAX];
int t2[MAX2]; // MAX2 = MAX*MAX
W każdym wierszu tablicy t1 znajdują się uporządkowane rosnąco (w obrębie
wiersza) liczby naturalne. Proszę napisać funkcję przepisującą wszystkie
singletony (liczby występujące dokładnie raz) z tablicy t1 do t2, tak aby
liczby w tablicy t2 były uporządkowane rosnąco. Pozostałe elementy tablicy t2
powinny zawierać zera.
*/
#include <iostream>
using namespace std;

const int max = 3;

void wypisz(int t2[max*max])
{
	for (int i = 0; i < max*max; i++)
	{
		cout << t2[i] << " " << i << endl;
	}
}

void wypisz_2(int t[max][max])
{
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			cout << t[i][j] << "\t ";
		}
		cout << endl;
	}
	cout << endl;
}

void wpisz(int t[max][max])
{
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			t[i][j] = i+j;
		}
		cout << endl;
	}
	cout << endl;
}

void singletony(int t1[max][max])
{
	for (int i = 0; i < max; i++)	//pozbywanie się powtarzających elementów
	{
		for (int j = 0; j < max; j++)
		{
			for (int k = 0; k < max; k++)
			{
				for (int h = 0; h < max; h++)
				{
					if (i == k && j == h)
						break;
					if (t1[i][j] == t1[k][h])
						t1[k][h] = -999;
				}
			}
		}
	}


}

int counter;
void przepisz(int t1[max][max], int t2[max*max])
{
	
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			if (t1[i][j] != -999)
			{
				t2[counter] = t1[i][j];
				cout << "counter = " << counter << "\t" << t2[counter] << endl;
				counter++;
			}
		}
	}
	for (int i = counter; i < max * max; i++)
	{
		t2[i] = 0;
		cout << "counter = " << counter << "\t" << t2[i] << endl;
	}
}

int main()
{
	int t1[max][max];
	int t2[max*max]; // MAX2 = MAX*MAX

	wpisz(t1);
	wypisz_2(t1);
	singletony(t1);
	wypisz_2(t1);
	przepisz(t1, t2);
	wypisz(t2);
}