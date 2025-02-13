#include <iostream>
#include <vector>
#include <limits.h>
#include <cstring>
using namespace std;

struct Node {
	int from;
	int to;
	int cost;
	Node(int from, int to, int cost):from(from), to(to), cost(cost){}
};

int map[30][30] = { 0, };
vector<Node> edge;
int *dist;
bool B_F(int W, int H) {
	int V = W * H;
	dist = new int[V];
	fill(dist, dist + V, INT_MAX);
	dist[W*(H-1)] = 0;

	for (int i = 0; i < V - 1; i++) {
		for (auto iter = edge.begin(); iter != edge.end(); iter++) {
			if (dist[iter->from] == INT_MAX) {
				continue;
			}
			if (dist[iter->to] > dist[iter->from] + iter->cost) {
				dist[iter->to] = dist[iter->from] + iter->cost;
			}
		}
	}

	for (auto iter = edge.begin(); iter != edge.end(); iter++) {
		if (dist[iter->from] == INT_MAX) {
			continue;
		}
		if (dist[iter->to] > dist[iter->from] + iter->cost) {
			return true;
		}
	}
	return false;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int W, H;
	cin >> W >> H;
    int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };
	while (!(W == 0 && H == 0)) {
		int G;
		cin >> G;
		for (int i = 0; i < G; i++) {
			int X, Y;
			cin >> X >> Y;
			map[H-Y-1][X] = -1;
		}
		int E;
		cin >> E;
		for (int i = 0; i < E; i++) {
			int X1, X2, Y1, Y2, T;
			cin >> X1 >> Y1 >> X2 >> Y2 >> T;
            
            edge.push_back(Node((H - Y1 - 1)*W + X1, (H-Y2-1)*W + X2, T));

			map[H-Y1-1][X1] = 1;
		}

		
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
                if( i==0 && j == W-1){
                    continue;
                }
				if (map[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						int nx = j + dx[k];
						int ny = i + dy[k];
						if (nx >= 0 && ny >= 0 && nx < W && ny < H) {
							if (map[ny][nx] != -1) {
								edge.push_back(Node(i*W + j, ny*W + nx, 1));
							}
						}
					}
				}
			}
		}
		if (B_F(W,H)) {
			cout << "Never\n";
		}
		else {
			if (dist[W - 1] == INT_MAX) {
				cout << "Impossible\n";
			}
			else {
				cout << dist[W-1] << "\n";
			}
		}
		cin >> W >> H;
		memset(map, 0, sizeof(map));
		edge.clear();
		delete[] dist;
	}
	return 0;
}