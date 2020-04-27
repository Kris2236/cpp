/* Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie, czy liczba ta
 * jest iloczynem dowolnych dwóch kolejnych wyrazów ciągu Fibonacciego.	*/

#include <iostream>

using namespace std;

#ifndef TEST
int main()
{
	int a;
	cin >> a;

	bool result = false;
	int fib1 = 0;
	int n = 0;
	int f1 = 0;
	int f2 = 1;
	int f2_tmp = 0;

	int fib2 = 0;
	int n2 = 0;
	int f12 = 0;
	int f22 = 1;
	int f2_tmp2 = 0;


	while (a >= fib1 && !result)
	{
		if (n == 0)
		{
			n++;
			fib1 = 0;
		}
		else if (n == 1)
		{
			n++;
			fib1 =1;
		}
		else
		{
			n++;
			fib1 = f1 + f2;
			f2_tmp = f2;
			f2 = f1 + f2;
			f1 = f2_tmp;
		}
		cout << "FIB1: " << fib1 << endl;
		
		while (a >= fib2)
		{
			if (n2 == 0)
			{
				n2++;
				fib2 = 0;
			}
			else if (n2 == 1)
			{
				n2++;
				fib2 = 1;
			}
			else
			{
				n2++;
				fib2 = f12 + f22;
				f2_tmp2 = f22;
				f22 = f12 + f22;
				f12 = f2_tmp2;
			}
			cout << "FIB2: " << fib2 << endl;

			if (fib1 * fib2 == a)
				result = true;
		}

		fib2 = 0;
		n2 = 0;
		f12 = 0;
		f22 = 1;
		f2_tmp2 = 0;

	}

	if (result)
		cout << "TAK" << endl;
	else
		cout << "NIE" << endl;

	return 0;
}
#endif