/*	Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie,
czy liczba ta jest wielokrotnością dowolnego wyrazu ciągu danego wzorem
A(n)=n*n+n+1.*/

#include <iostream>

using namespace std;

int ciag(int n)
{
	int c = n * n + n + 1;
	return c;
}

int main()
{
	int a = 0;
	int x = 0;
	int y = 0;
	int i = 1;
	int j = 0;
	bool result = false;

	cout << "Podaj liczbę: ";
	cin >> a;

	while (x <= a && !result)
	{
		x = ciag(i);
		while (y <= a && !result)
		{
			y = x * j;
			j++;

			if (y == a)
				result = true;
		}

		j = 0;
		cout << x << endl;
		i++;
	}

	if (result == true)
		cout << "TAK" << endl;
	else
		cout << "NIE" << endl;
}
