#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> matrix_mul(const vector<vector<int>>& A, const vector<vector<int>>& B){
    int n = A.size();
    int m = A[0].size();
    int k = B[0].size();
    // зная размеры двух матриц, мы можемм создать 3
    vector<vector<int>> C(n, vector<int>(k));
    
    // по первой матрицы, по строкам
    for (int i = 0; i < n; ++i){
        // по столбцам второй матрицы
        for (int j = 0; j < k; ++j){
            // сумма произведений
            for (int k = 0; k < m; ++k){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main(){
    vector<vector<int>> A = {
        {1, 2, 3},
        {3, 1, 2}
    };
    vector<vector<int>> B = {
        {1, 2},
        {3, 2},
        {1, 2}
    };
    vector<vector<int>> C = {
        {10, 12},
        {8, 12}
    };

    cout << (matrix_mul(A, B) == C);
}