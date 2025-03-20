#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> v[32001];
int indegree[32001] = { 0, };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
		indegree[B]++;
	}

	deque<int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push_back(i);
		}
	}
	while (!q.empty()) {
		int num = q.front();
		q.pop_front();
		cout << num << " ";
		for (auto iter = v[num].begin(); iter != v[num].end(); iter++) {
			indegree[*iter]--;
			if (indegree[*iter] == 0) {
				q.push_back(*iter);
			}
		}
	}

	return 0;
}