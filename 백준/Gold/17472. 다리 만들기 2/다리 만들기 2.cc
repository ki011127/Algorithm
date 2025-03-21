#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int to;
	int from;
	int weight;
	Edge(int to, int from, int weight) : to(to), from(from), weight(weight){}
	bool operator < (const Edge & a) const {
		return weight < a.weight;
	}
};

int map[10][10];
int parent[7];
int N, M;
vector<Edge> e;
void make_island(int num, int x, int y);
void make_candidate_bridge(int x, int y);

void init_union_find(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	else {
		return parent[a] = find(parent[a]);
	}
}

void uni(int a, int b) {
	int a_root = find(a);
	int b_root = find(b);
	if (a_root != b_root) {
		parent[a_root] = b_root;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				map[i][j] = -1;
			}
		}
	}
	int island_num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == -1) {
				map[i][j] = island_num;
				make_island(island_num, j, i);
				island_num++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0) {
				make_candidate_bridge(j, i);
			}
		}
	}
	
	sort(e.begin(), e.end());
	init_union_find(island_num - 1);
	int count = 0;
	int min_cost = 0;

	for (auto iter = e.begin(); iter != e.end(); iter++) {
		if (find(iter->from) != find(iter->to)) {
			min_cost += iter->weight;
			uni(iter->from, iter->to);
			count++;
		}
		if (count == island_num - 2) {
			cout << min_cost;
			return 0;
		}
	}

	cout << "-1";
	return 0;


}


void make_island(int num, int x, int y) {
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (map[ny][nx] == -1 && nx<M && ny<N && nx >= 0 && ny >= 0) {
			map[ny][nx] = num;
			make_island(num, nx, ny);
		}
	}
}

void make_candidate_bridge(int x, int y) {
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int cur_island_num = map[y][x];
	for (int i = 0; i < 4; i++) {
		int move_x = dx[i];
		int move_y = dy[i];
		int nx = x + move_x;
		int ny = y + move_y;
		int weight = 0;
		while (nx >= 0 && ny >= 0 && nx < M && ny < N) {
			if (map[ny][nx] != 0) {
				if (map[ny][nx] != cur_island_num && weight > 1) {
					e.push_back(Edge(cur_island_num, map[ny][nx], weight));
				}
				break;
			}
			weight++;
			nx = nx + move_x;
			ny = ny + move_y;
		}
	}
}

