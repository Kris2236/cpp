/*	6. Dany jest ciąg zer i jedynek zapisany w tablicy int t[N].Proszę napisać funkcję, która odpowiada na pytanie czy jest możliwe pocięcie ciągu na kawałki z których
każdy reprezentuje liczbę pierwszą.Długość każdego z kawałków nie może przekraczać 30. Na przykład dla ciągu 111011 jest to możliwe, a dla ciągu 110100 nie jest możliwe.*/

#include <iostream>
using namespace std;
const int N = 9;

void wypisz(int t[N])
{
	for (int i = 0; i < N+2 ;i++)
	{
		cout << t[i] << "\t";
	}
}

bool prime(int a)
{
	int n = 2;		// liczba 
	int i = 1;		//dzielniki
	int counter = 0;	//licznik dzielnikow
	int t_prime[11] = { 0 };
	int pozycja = 0;

	for (int n = 2; n <= 31; n++)
	{
		while (i <= 31)
		{
			if (n % i == 0)
				counter++;
			i++;
		}

		if (counter == 2)
		{
			t_prime[pozycja] = n;
			pozycja++;
			cout << n << endl;
			if (a == n)	return 1;
		}

		counter = 0;
		i = 1;
	}
	wypisz(t_prime);
	return 0;
}

bool spr(int p, int k, int t[N])
{
	int s1 = 0, s2 = 0;

	for (int i = p; i <= k; i++)	// suma pierwszego ciągu
		s1 += t[i];

	if (prime(s1) == 0)	return 0;

	for (int i = k+1; i < N; i++)	// suma drugiego ciagu
		s2 += t[i];

	if (prime(s2) == 0)	return 0;

	return 1;
}

void podziel(int t[N])
{
	bool koniec = false;
	for (int p = 0; p < N && !koniec; p++)
	{
		for (int k = p+1; k < N && !koniec; k++)
		{
			if (spr(p, k, t))
				koniec = true;
		}
	}
	if (koniec) cout << "TAK" << endl;
	else		cout << "NIE" << endl;
}

int main()
{
	//int t[N] = { 1,1,1,0,1,1 };
	int t[N] = { 1,1,0,0,1,0 };
	podziel(t);

}
