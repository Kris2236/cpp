/* 1. Dana jest tablica int t[MAX][MAX]. Proszę napisać funkcję wypełniającą tablicę
liczbami naturalnymi po spirali. */

#include <iostream>

using namespace std;

int main()
{
	const int MAX = 20;
	bool flag = false;
	int count = 1;
	int x = 0;
	int y = 0;

	//cout << "Podaj rozmiar tablic : ";
	//cin >> MAX;

	int tab[MAX][MAX];

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			tab[i][j] = 0;
		}
	}

	if (MAX % 2 == 0)
	{
		x = (MAX / 2);
		y = (MAX / 2) - 1;
	}
	else
	{
		x = MAX / 2;
		y = MAX / 2;
	}

	count = 1;
	tab[x][y] = count;
	count++;
	int n = 1;
	while (1)
	{
		//W Prawo n razy
		for (int i = 0; i < n; i++)
		{
			y++;
			//cout << "tab[" << x << "] [" << y << "] = " << count << endl;
			tab[x][y] = count;
			count++;
			if (count == MAX * MAX + 1)
				break;
		}
		if (count == MAX * MAX + 1)
			break;

		//W Górę n razy
		for (int i = 0; i < n; i++)
		{
			x--;
			//cout << "tab[" << x << "] [" << y << "] = " << count << endl;
			tab[x][y] = count;
			count++;
			if (count == MAX * MAX + 1)
				break;
		}
		if (count == MAX * MAX + 1)
			break;

		n++;

		//W Lewo n razy
		for (int i = 0; i < n; i++)
		{
			y--;
			//cout << "tab[" << x << "] [" << y << "] = " << count << endl;
			tab[x][y] = count;
			count++;
			if (count == MAX * MAX + 1)
				break;
		}
		if (count == MAX * MAX + 1)
			break;

		//W Dół n razy
		for (int i = 0; i < n; i++)
		{
			x++;
			//cout << "tab[" << x << "] [" << y << "] = " << count << endl;
			tab[x][y] = count;
			count++;
			if (count == MAX * MAX + 1)
				break;
		}
		if (count == MAX * MAX + 1)
			break;

		n++;
	}
	
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (tab[i][j] < 10)
			{
				cout << "  " << tab[i][j] << "  ";
			}
			else if(tab[i][j] < 100)
				cout << " " << tab[i][j] << "  ";
			else if (tab[i][j] < 1000)
				cout << " " << tab[i][j] << " ";
			else if (tab[i][j] < 10000)
				cout << tab[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}