#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <deque>
#include <string.h>

using namespace std;
int N, M;
int shortest[500][500] = { 0, };
struct Node{
	int dst;
	int w;

	Node(int dst, int w):dst(dst),w(w){}
	Node(){}

	bool operator<(const Node &a) const {
		return w > a.w;
	}
};

int bfs(int N, int M, int S, int D) {
	vector<Node> edge[500];
	for (int i = 0; i < M; i++) {
		int U, V, P;
		cin >> U >> V >> P;
		edge[U].push_back(Node(V, P));
	}
	int visited[500] = { 0, };
	priority_queue <Node> pq;
	int table[500];
	fill(table, table + 500, INT_MAX);
	table[S] = 0;
	pq.push(Node(S, 0));
	vector<int> candidate[500];
	while (!pq.empty()) {
		Node cur_node = pq.top();
		pq.pop();

		if (visited[cur_node.dst] == 1) {
			continue;
		}
		visited[cur_node.dst] = 1;
		
		for (auto iter = edge[cur_node.dst].begin(); iter != edge[cur_node.dst].end(); iter++) {
			if (table[iter->dst] > cur_node.w + iter->w) {
				table[iter->dst] = cur_node.w + iter->w;
				pq.push(Node(iter->dst, table[iter->dst]));
				candidate[iter->dst].clear();
				candidate[iter->dst].push_back(cur_node.dst);
			}
			else if (table[iter->dst] == cur_node.w + iter->w) {
				candidate[iter->dst].push_back(cur_node.dst);
			}
		}
	}
	deque<int> dq;
	for (auto iter = candidate[D].begin(); iter != candidate[D].end(); iter++) {
		dq.push_back(*iter);
		shortest[*iter][D] = 1;
	}

	while (!dq.empty()) {
		int v = dq.front();
		dq.pop_front();
		for (auto iter = candidate[v].begin(); iter != candidate[v].end(); iter++) {
			if (shortest[*iter][v] != 1) {
				dq.push_back(*iter);
				shortest[*iter][v] = 1;
			}
		}
	}

	fill(table, table + 500, INT_MAX);
	memset(visited, 0, sizeof(int)*500);
	table[S] = 0;
	pq.push(Node(S, 0));
	while (!pq.empty()) {
		Node cur_node = pq.top();
		pq.pop();

		if (visited[cur_node.dst] == 1) {
			continue;
		}
		visited[cur_node.dst] = 1;

		for (auto iter = edge[cur_node.dst].begin(); iter != edge[cur_node.dst].end(); iter++) {
			if (shortest[cur_node.dst][iter->dst] == 1) {
				continue;
			}

			if (table[iter->dst] > cur_node.w + iter->w) {
				table[iter->dst] = cur_node.w + iter->w;
				pq.push(Node(iter->dst, table[iter->dst]));
			}
		}
	}
	memset(shortest, 0, sizeof(int) * 500 * 500);
	if (table[D] == INT_MAX) {
		return -1;
	}
	return table[D];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	while (!(N == 0 && M == 0)) {
		int S, D;
		cin >> S >> D;

		cout << bfs(N, M, S, D) << "\n";
		cin >> N >> M;
	}
	return 0;
}