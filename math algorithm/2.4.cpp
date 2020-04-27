/* Liczba dwu-trzy-piątkowa w rozkładzie na czynniki pierwsze nie posiada innych
czynników niż 2,3,5. Jedynka też jest taką liczbą. Napisz program, który wylicza
ile takich liczb znajduje się w przedziale od 1 do N włącznie. */

#include <iostream>

using namespace std;

int ile_2_3_5(int a)
{
	int tmp = a;
	int i = 0;

	while(tmp > 1)
	{
		tmp = tmp - 2;
		i++;
	}

		tmp = a;
		while (tmp > 2)
	{
		tmp = tmp - 3;
		i++;
	} 

		tmp = a;
		while (tmp > 4)
	{
		tmp = tmp - 5;
		i++;
	} 

		return i;
}

int main()
{
	int a;

	cout << "Podaj n: ";
	cin >> a;

	cout << "w przedziale 1 do n jest: " << ile_2_3_5(a) << "   2,3 i 5" << endl;


}