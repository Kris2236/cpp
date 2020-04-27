/*		3. Napisać program generujący i wypisujący liczby pierwsze mniejsze od N metodą Sita Eratostenesa		*/

#include <iostream>
using namespace std;

int main()
{
	int n=0;
	bool tab_b[1000000];

	cout << "Podaj n:";
	cin >> n;
	
	for (int i = 0; i < n - 1; i++)				//ustawiamy całą tablicęna true, elementy tab reprezentuja liczby pierwsze: np. t[0] -> 2
	{
		tab_b[i] = true;
	}

	for (int i = 0; i < n - 1; i++)				//zaczynamy od 0
	{
		if (tab_b[i] == true)					//jeśli liczba ani jej wielokrotność nie była użyta to...
		{
			for (int j = 0; j < n - 1; j++)
			{
				if ((j + 2) % (i + 2) == 0)		//żeby uniknąć dzielenia przez 0 dodajemy 2
				{
					tab_b[j] = false;			// jeśli liczba jest wielokrotnością i ustawiamy false, oznacza to że liczba była użyta
				}
			}
			cout << i + 2 << endl;
		}
	}

	return 0;
}
