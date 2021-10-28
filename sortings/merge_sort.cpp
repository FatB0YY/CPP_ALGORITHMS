#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> merge(vector<int>& left, vector<int>& right) {
	vector<int> merged;
	int left_idx = 0;
	int right_idx = 0;
	while (left_idx < left.size() && right_idx < right.size()) {
		if (left[left_idx] <= right[right_idx]) {
			merged.push_back(left[left_idx++]);
		}
		else {
			merged.push_back(right[right_idx++]);
		}
	}
	while (left_idx < left.size()) {
		merged.push_back(left[left_idx++]);
	}
	while (right_idx < right.size()) {
		merged.push_back(right[right_idx++]);
	}
	return merged;
}

void merge_sort(vector<int>& arr) {
	if (arr.size() <= 1) return;
	vector<int> left, right;
	int n = arr.size() / 2;
	for (int i = 0; i < n; i++) {
		left.push_back(arr[i]);
	}
	for (int i = n; i < arr.size(); i++) {
		right.push_back(arr[i]);
	}

	merge_sort(left);
	merge_sort(right);

	arr = merge(left, right);
}


int main() {
	vector<int> arr;
	const int n = rand() % 100;
	for (int i = 0; i < n; i++) {
		arr.push_back(rand());
	}

	vector<int> arr_copy = arr;

	// моя сортировка
	merge_sort(arr);
	// сортировка C++
	sort(arr_copy.begin(), arr_copy.end());

	cout << (arr_copy == arr) << endl;
}

