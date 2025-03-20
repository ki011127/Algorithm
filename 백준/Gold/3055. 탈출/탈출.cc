#include <stdio.h>
#include <algorithm>
#include <deque>
using namespace std;
std::deque<int> w_dq_x;
std::deque<int> w_dq_y;
std::deque<int> d_dq_x;
std::deque<int> d_dq_y;
int water(char **map, int R, int C);
int D_move(char **map, int R, int C, int **visit_map);
int main(void) {
	int R, C;
	scanf("%d %d", &R, &C);
	char** map = new char*[R];
	for (int i = 0; i < R; i++) {
		map[i] = new char[C];
		scanf("%s", map[i]);
	}
	int** visit_map = new int*[R];
	for (int i = 0; i < R; i++) {
		visit_map[i] = new int[C];
	}
	int w_count = 0;
	int d_count = 1;
	int time = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '*') {
				w_dq_x.push_back(j);
				w_dq_y.push_back(i);
				w_count++;
			}
			if (map[i][j] == 'S') {
				visit_map[i][j] = 1;
				d_dq_x.push_back(j);
				d_dq_y.push_back(i);
			}
		}
	}
	int flag = 0;
	while (!w_dq_x.empty() || !d_dq_x.empty()) {
		time++;
		int new_wcount = 0;
		for (int i = 0; i < w_count; i++) {
			new_wcount += water(map, R, C);
		}
		w_count = new_wcount;
		int new_dcount = 0;
		for (int i = 0; i < d_count; i++) {
			int c = D_move(map, R, C, visit_map);
			if (c == -1) {
				printf("%d", time);
				return 0;
			}
			new_dcount += c;
		}
		d_count = new_dcount;

	}

	printf("KAKTUS");


	return 0;
}

int water(char **map, int R, int C) {
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };
	int x = w_dq_x.front();
	int y = w_dq_y.front();
	int count = 0;
	w_dq_x.pop_front();
	w_dq_y.pop_front();
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < C && ny < R) {
			if (map[ny][nx] == '.' || map[ny][nx] == 'S') {
				w_dq_x.push_back(nx);
				w_dq_y.push_back(ny);
				map[ny][nx] = '*';
				count++;
			}
		}
	}
	return count;
}

int D_move(char **map, int R, int C, int **visit_map) {
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };
	int x = d_dq_x.front();
	int y = d_dq_y.front();
	int count = 0;
	d_dq_x.pop_front();
	d_dq_y.pop_front();
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < C && ny < R) {
			if (map[ny][nx] == '.' && visit_map[ny][nx]!=1) {
				visit_map[ny][nx] = 1;
				d_dq_x.push_back(nx);
				d_dq_y.push_back(ny);
				count++;
			}
			else if (map[ny][nx] == 'D') {
				return -1;
			}
		}
	}
	return count;
}