#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void counting_sort(vector<int>& arr) {
	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < arr.size(); i++){
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	vector<int> bucket(max - min + 1);
	for (int i = 0; i < arr.size(); i++) {
		bucket[arr[i] - min]++;
	}
	arr.clear();
	for (int i = 0; i < bucket.size(); i++) {
		int count = bucket[i]; // i + min
		for (int j = 0; i < count; j++) {
			arr.push_back(i + min);
		}
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
	counting_sort(arr);
	// сортировка C++
	sort(arr_copy.begin(), arr_copy.end());

	cout << (arr_copy == arr) << endl;
}

