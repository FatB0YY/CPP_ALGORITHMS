#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int patrition(vector<int>& arr, int i, int j) {
	int P = rand() % (j - i) + i;
	swap(arr[P], arr[i]);
	P = i;
	int S1_idx = i;
	int S2_idx = i;
	for (int k = i + 1; k < j; k++) {
		if (arr[k] >= arr[P]) {
			++S2_idx;
		}
		else {
			++S1_idx;
			swap(arr[S1_idx], arr[k]);
			++S2_idx;
		}
	} // =>  27 | 12 16 | 39 27 38 осталось поменять 27
	swap(arr[P], arr[S1_idx]);
	P = S1_idx;
	return P;
}

void quick_sort(vector<int>& arr, int i, int j) {
	if (i == j) return;
	int P = patrition(arr, i, j); // [i, P - 1] < P // [P + 1, j] >= P
	quick_sort(arr, i, P);
	quick_sort(arr, P + 1, j);
}

void quick_sort(vector<int>& arr) {
	quick_sort(arr, 0, arr.size());
}

int main() {
	vector<int> arr;
	const int n = rand() % 100;
	for (int i = 0; i < n; i++) {
		arr.push_back(rand());
	}

	vector<int> arr_copy = arr;

	// моя сортировка
	quick_sort(arr);
	// сортировка C++
	sort(arr_copy.begin(), arr_copy.end());

	cout << (arr_copy == arr) << endl;
}

