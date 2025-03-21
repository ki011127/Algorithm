#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct Node {
	int des;
	int w;
	Node(int des, int w):des(des),w(w){}
	Node(){}
	bool operator<(const Node &a) const {
		return w > a.w;
	}
};

vector<Node> edge[1001];

void bfs(int n, int k) {
	priority_queue<Node> pq;
	priority_queue<int> dist[1001];
	pq.push(Node(1, 0));
	dist[1].push(0);
	while (!pq.empty()) {
		Node cur_node = pq.top();
		pq.pop();
		for (auto iter = edge[cur_node.des].begin(); iter != edge[cur_node.des].end(); iter++) {
			if (dist[iter->des].size() < k) {
				dist[iter->des].push(cur_node.w + iter->w);
				pq.push(Node(iter->des, cur_node.w + iter->w));
			}
			else if (dist[iter->des].size() == k && dist[iter->des].top() > cur_node.w + iter->w) {
				dist[iter->des].pop();
				dist[iter->des].push(cur_node.w + iter->w);
				pq.push(Node(iter->des, cur_node.w + iter->w));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k) {
			cout << "-1\n";
		}
		else {
			cout << dist[i].top() << "\n";
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back(Node(b, c));
	}

	bfs(n, k);
	return 0;
}