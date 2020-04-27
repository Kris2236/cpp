/*	Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie,
czy liczba naturalna jest palindromem, a następnie czy jest palindromem w systemie
dwójkowym.*/

#include <iostream>

using namespace std;

int palindrom(int a, int number)
{
	int x = 0, p = a;
	while (a > 0)
	{
		x = x + a % number;
		x *= number;
		a /= number;
	}
	x = x / number;
	cout << x;
	if (x == p) 
		cout << " TAK w systemie (" << number << ")" << endl;
	else
		cout << " NIE w systemie (" << number << ")" << endl;
	return 0;
}


int main()
{
	int a = 0;

	cout << "Pdaj liczbe: ";
	cin >> a;
	palindrom(a, 10);
	palindrom(a, 2);
}
