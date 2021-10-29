#include <iostream>

using namespace std;

int bin_pow1(int a, int n) {
	if (n == 0) return 1;
	if (n % 2 == 1) {
		return bin_pow1(a, n - 1) * a;
	} 
	/*
	 должны написать так, 
	 чтобы эти ф-ции не плодили друг друга.
	 не теряем преимущество
	*/
	int b = bin_pow1(a, n / 2);
	return b * b;
}

int bin_pow2(int a, int n) {
	int result = 1;
	// проходимся по битам числа
	while (n != 0) {
		// если последний бит нашего числа = 1
		if (n & 1) {
			result *= a;
		}
		// n / 2
		n >>= 1;
		a *= a;
		// a, a^2, a^4, a^8, ...
	}
	return result;
}

int main() {
	cout << (bin_pow2(2, 10) == 1024) << endl;
	cout << (bin_pow2(3, 5) == 243) << endl;
	cout << (bin_pow2(3, 15) == 14348907) << endl;
}

