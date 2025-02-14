#include <iostream>
#include <cstring>
#include <limits.h>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int matrix[2][500];
    for(int i = 0; i<N;i++){
        cin >> matrix[0][i] >> matrix[1][i];
    }
    int dp[500][500];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i<N-1; i++){
        dp[i][i+1] = matrix[0][i] * matrix[1][i] * matrix[1][i+1];
    }

    for(int gap = 2; gap<N; gap++){
        for(int i = 0; i<N-gap; i++){
            int j = i+gap;
            dp[i][j] = INT_MAX;
            for(int k = i; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+(matrix[0][i]*matrix[1][k]*matrix[1][j]));
            }
        }
    }
    cout << dp[0][N-1];
}