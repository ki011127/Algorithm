#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int V, E;


struct Node {
	int to;
	int w;
	Node(int to,int w):to(to), w(w){}
	Node(){}

	bool operator<(const Node &node) const {
		return w > node.w;
	}
};

vector<Node> edge[20001];
int visited[20001] = { 0, };
int *table;
void dij(int start) {
	table[start] = 0;
	priority_queue<Node> q;
	q.push(Node(start, 0));
	while (!q.empty()) {
		Node current = q.top();
		q.pop();
		if (visited[current.to] == 1) {
			continue;
		}
		visited[current.to] = 1;
		for (auto iter = edge[current.to].begin(); iter != edge[current.to].end(); iter++) {
			if (table[iter->to] > current.w + iter->w) {
				table[iter->to] = current.w + iter->w;
				q.push(Node(iter->to, table[iter->to]));
			}
		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E;
	int start;
	cin >> start;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back(Node(v, w));
	}
	table = new int[V + 1];
	fill(table, table + V + 1, INT_MAX);
	dij(start);
	for (int i = 1; i <= V; i++) {
		if (table[i] != INT_MAX) {
			cout << table[i] << "\n";
		}
		else {
			cout << "INF\n";
		}
	}
	return 0;
}