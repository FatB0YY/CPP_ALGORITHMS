#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		int cur = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > cur) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = cur;
	}
}


int main() {
	vector<int> arr;
	const int n = rand() % 100;
	for (int i = 0; i < n; i++) {
		arr.push_back(rand());
	}

	vector<int> arr_copy = arr;

	// моя сортировка
	insertion_sort(arr);
	// сортировка C++
	sort(arr_copy.begin(), arr_copy.end());

	cout << (arr_copy == arr) << endl;
}

