#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << (51 & 25) << endl; // 17
    cout << (51 | 25) << endl; // 59
    cout << (51 ^ 25) << endl; // 42
    cout << (~23) << endl; // -24
    cout << (~23u) << endl; // 4294967272
    cout << (12 << 2) << endl; // 48
    cout << (12 >> 2) << endl; // 3
    cout << endl;
    cout << (1 << 4) << endl; // 16
    cout << (1 << 5) << endl; // 32
    cout << (1 << 6) << endl; // 64
    cout << (1 << 7) << endl; // 128

    int n = 17; // 0...00010001
    // 0...00010101
    int i = 2;

    n = n | (1 << i); // 21
    n = n | (1 << i); // 21 еще раз

    n = n & ~(1 << i); // 17 вернем

    n = n ^ (1 << i); // поменяем любой бит на противополож

    if ((n & (1 << i)) == 0); // конкретный бит нашего числа 1 или 0


    // битмаски
    vector<int> arr{ 1, 2, 3, 4 };
    // vector<string> arr{ "AA", "BB", "AC", "RT", "QW" }; 
    int n = arr.size();

    for (int mask = 0; mask < (1 << n); mask++) {
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            if (mask &(1 << i)) {
                cout << arr[i] << " ";
            }
        }
        cout << "}";
        cout << endl;
    }

}

