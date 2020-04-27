/* Napisać program wczytujący trzy liczby naturalne a,b,n i wypisujący rozwinięcie
dziesiętne ułamka a/b z dokładnością do n miejsc po kropce dziesiętnej. (n jest rzędu 100)*/

#include <iostream>

using namespace std;

int main()
{
	int a, b, n, tmp;

	cout << "Podaj a,b";
	cin >> a;
	cin >> b;
	cout << "Podaj dokładność: ";
	cin >> n;

	if (a > b)
		cout << a / b;
	else
		cout << "0";
	cout << ",";
	for(int i =0; i <n; i++)
	{
		a *= 10;
		tmp = a;
		a = a % b;
		tmp = tmp / b;
		cout <<tmp;
	}
}