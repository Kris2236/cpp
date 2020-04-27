/* 3. Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę napisać
funkcję który odpowiada na pytanie, czy istnieje wiersz w tablicy w którym każda
z liczb zawiera przynajmniej jedna cyfrę parzystą. */

#include <iostream>

using namespace std;

const int max = 10;

void zerowanie(int t[max][max])
{
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			t[i][j] = 0;
		}
	}
	
}

bool spr_liczbe(int a)	//spr czy istnieje cyfra parzysta w liczbie
{
	int tmp;
	while (a > 0)
	{
		tmp = a % 10;
		if (tmp % 2 == 0)
		{
			cout << "p" << endl;
			return 1;
		}
		a = a / 10;
	}
	cout << "np" << endl;;
	return 0;
}

bool spr_wiersz(int t[max][max])
{
	int tmp;
	int counter=1;
	for (int i = 0; i < max; i++)		//sprawdzamy wiersze
	{
		for (int j = 0; j < max; j++)	//spr wszystkieelementy w n-tym wierszu
		{
			//cout << t[i][j] << " i"<< i << " j" << j << endl;
			if (counter == max)	
				return 1;
			if (!spr_liczbe(t[i][j]))
				break;
			counter++;
		}
		cout << "NOWY WIERSZ" << endl;
		counter = 1;
	}
	return 0;
}

void wypisz(int t[max][max])
{
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			cout << t[i][j] << ", ";
		}
		cout << endl;
	}

}

void wpisz(int t[max][max])
{
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			t[i][j] = 3;
		}
		cout << endl;
	}

}

int main()
{
	int t[max][max];
	int x;
	zerowanie(t);
	wpisz(t);
	wypisz(t);

	x = spr_wiersz(t);

	if(x == 0)	cout << "NIE.";
	else		cout << "TAK";
}