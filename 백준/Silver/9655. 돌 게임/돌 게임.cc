#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    bool dp[1001] = {false};
    dp[1] = true;   // 1개 → 상근 승
    dp[2] = false;  // 2개 → 창영 승
    dp[3] = true;   // 3개 → 상근 승

    for (int i = 4; i <= N; i++) {
        // dp[i-1] == false 또는 dp[i-3] == false → SK가 이길 수 있음
        if (!dp[i-1] || !dp[i-3])
            dp[i] = true;
        else
            dp[i] = false;
    }

    if (dp[N])
        cout << "SK";
    else
        cout << "CY";

    return 0;
}