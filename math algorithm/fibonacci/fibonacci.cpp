#include <iostream>

unsigned fibonacciSum(unsigned n0, unsigned n) {
	unsigned sum = 0;
	unsigned f1 = 1, f2 = 1, iter = 0;
	while (++iter <= n) {
		if (iter >= n0 && iter <= n) {
			sum += f1;
		}
		f2 = f2 + f1;
		f1 = f2 - f1;
	}
	return sum;
}

int main() {
	unsigned sum;
	std::cout << "Prosze podac sume: " << std::endl;
	std::cin >> sum;

	unsigned n1 = 1, n2 = 1, nth = 0;
	while (n1 <= sum) {
		nth++;
		n2 = n2 + n1;
		n1 = n2 - n1;
	}

	for (unsigned i = 1; i < nth; i++) {
		for (unsigned j = i + 1; j <= nth; j++) {
			if (fibonacciSum(i, j) == sum) {
				std::cout << "Istnieje spojny podciag - od elementu "
					<< i << " do elementu " << j << " (wlacznie)."
					<< std::endl;
			}
		}
	}
}
