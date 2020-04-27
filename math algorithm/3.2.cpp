/* 2. Napisać program wczytujący dwie liczby naturalne i odpowiadający
na pytanie czy są one zbudowane z takich samych cyfr, np. 123 i
321, 1255 i 5125, 11000 i 10001. */

#include <iostream>

using namespace std;

int main()
{
	int a;
	int b;
	int tab_a[10] = { 0,0,0,0,0,0,0,0,0,0 }, tab_b[10] = { 0,0,0,0,0,0,0,0,0,0 };
	bool flaga = false;

	cout << "Podaj liczbe:";
	cin >> a;

	cout << "Podaj druga liczbe:";
	cin >> b;

	while (a > 0)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (a % 10 == i)
				tab_a[i] += 1;
		}
		a = a / 10;
	}

	while (b > 0)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (b % 10 == i)
				tab_b[i] += 1;
		}
		b = b / 10;
	}

	for (int i = 0; i <= 9; i++)
	{
		cout << tab_a[i] << " b = " << tab_b[i] << endl;
		if (tab_a[i] != tab_b[i])
		{
			cout << "NIE";
			break;
		}

		if(i==9)
			cout << "TAK";
	}
	
	return 0;
}