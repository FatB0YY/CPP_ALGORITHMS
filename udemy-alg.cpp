#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> a, int x) { // O(n), где n - длина массива = c*n
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

void swap(int& a, int& b) { // O(1) = c
    int t = a;
    a = b;
    b = t;
}

void cycle_nm1(int n, int m) { // O(max(n,m)) = O(n + m)
    for (int i = 0; i < n; i++) {
        cout << i;
    }
    for (int i = 0; i < m; i++) {
        cout << i;
    }
}

void cycle_nm2(int n, int m) { // O(n*m)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << i + j;
        }
    }
}

void cycle_n2(int n) { // O(n^2)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i + j;
        }
    }
}

void cycle_ij(int n) { // 
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) { // n + (n - 1) + 
            cout << i + j; // + (n - 2) + (n - 3) + ... + 1 == 
        } // == n*(n + 1)/2 
    } // n*(n + 1)/2 = 1/2*(n*n + n) = O(n^2)
}

void cycle_n123(int n) { // O(n^3 + n^2 + n) => O(n^2) !!!
    for (int i = 0; i < n; i++) {
        cout << i ;  // O(n)
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) { 
            cout << i + j; // O(n^2)
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) { 
            for (int k = 0; k < n; k++) {
                cout << i + j + k; // O(n^3)
            }
            
        }
    }
}

void cycle_abc123(int a, int b, int c) { // O(a + b^2 + c^3) 
    for (int i = 0; i < a; i++) { // тк мы не знаем точно a b и c 
        cout << i;  // O(a)
    }
    for (int i = 0; i < b; i++) {
        for (int j = i; j < b; j++) {
            cout << i + j; // O(b^2)
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = i; j < c; j++) {
            for (int k = 0; k < c; k++) {
                cout << i + j + k; // O(c^3)
            }

        }
    }
}

int cycle_log1(int a, int b, int c) { 
    int sum = 0;
    while (a != 0) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}


/*
    В цикле мы делаем n действий, а в самом цикле делаем log кол действий => O(n * log(n)), 
    здесь мы не используем a, тк на вход подается только n !!!
*/
int cycle_log2(int n) { // O(n * log(n))
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a = i;
        while (a != 0) {
            sum += a % 10;
            a /= 10;
        }
    }
    return sum;
}

int cycle_sqrt(int n) { // O(sqrt(n))
    // for (int i = 0; i < sqrt(n); i++) {
    for (int i = 0; i*i < n; i++) {
        cout << i;
    }
    
}

int cycle_n_plus2(int n) { // O(n)
    for (int i = 0; i < n; i+=2) { // n / 2 = 1/2 * n
        cout << i;
    }
}



int main()
{
    cout << "Hello World!" << endl;
}

