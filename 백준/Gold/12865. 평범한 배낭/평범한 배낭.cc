#include <iostream>
#include <algorithm>
using namespace std;

struct Data {
	int W;
	int V;
	Data(int W, int V):W(W),V(V){}
	Data(){}
};

int dp[101][100001] = { 0, };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K;
	cin >> N >> K;

	Data* data = new Data[N+1];
	for (int i = 1; i <= N; i++) {
		int W, V;
		cin >> W >> V;
		data[i] = Data(W, V);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < K+1; j++) {
			if (data[i].W <= j) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - data[i].W] + data[i].V);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}


	cout << dp[N][K];

	return 0;
}