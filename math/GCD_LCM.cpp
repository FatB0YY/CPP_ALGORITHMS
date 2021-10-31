#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int main() {
	cout << (gcd(15, 24) == 3) << endl;
}

