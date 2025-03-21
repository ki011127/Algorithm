#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

struct Node {
	int from;
	int to;
	int cost;
	Node(int from, int to, int cost):from(from), to(to), cost(cost){}

};

vector<Node> edge;
long* dist;
bool B_F(int V) {
	dist = new long[V + 1];
	fill(dist, dist + V + 1, INT_MAX);
	dist[1] = 0;
	for (int i = 0; i < V-1; i++) {
		for (auto e = edge.begin(); e != edge.end(); e++) {
			if (dist[e->from] == INT_MAX) {
				continue;
			}

			if (dist[e->to] > dist[e->from] + e->cost) {
				dist[e->to] = dist[e->from] + e->cost;
			}
		}
	}
	for (auto e = edge.begin(); e != edge.end(); e++) {
		if (dist[e->from] == INT_MAX) {
			continue;
		}

		if (dist[e->to] > dist[e->from] + e->cost) {
			return true;
		}
	}
	return false;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		edge.push_back(Node(A,B,C));
	}
	if (B_F(N)) {
		cout << "-1";
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INT_MAX) {
				cout << "-1\n";
			}
			else {
				cout << dist[i] << "\n";
			}
		}
	}
	return 0;
}