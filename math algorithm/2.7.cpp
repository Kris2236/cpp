/* 7. Napisać program wczytujący liczbę naturalną z klawiatury i rozkładający ją na
iloczyn 2 liczb o najmniejszej różnicy. Np. 30=5*6, 120=10*12.	*/

#include <iostream>
#include<cmath>

using namespace std;

int policz(int a) {
	int x;
	x = sqrt(a);
	while (x > 0) {
		if (a % x == 0) {
			cout << "tak"<<x<< ", "<< a/x <<endl;
			return 0;
		}
		x--;
	}
	return 0;
}

int main()
{
	int a = 0;

	cout << "Podaj liczbe: ";
	cin >> a;
	polic(a);
}
