#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve(int n) {
	// все эл. изначально будут равны true
	vector<bool> mark(n, true);
	// отдельный массив для простых чисел
	vector<int> primes;
	// сразу добавляем 2
	primes.push_back(2);

	// идем до корня нашего числа
	for (int i = 3; i * i <= n; i += 2) {
		if (mark[i]) {
			primes.push_back(i);
			// начинем сразу с квадрата
			for (int j = i*i; j < n; j += i) {  
				mark[j] = false;
			}
		}
	}
	for (int i = 3; i < n; i += 2) {
		if (mark[i]) {
			primes.push_back(i);
		}
	}
	return primes;
}

int main() {
	vector<int> primes = sieve(10000000);
	for (auto prime : primes) {
		cout << prime << " ";
	}
}

