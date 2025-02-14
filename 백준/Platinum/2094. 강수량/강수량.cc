#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct Data {
	int year;
	int r;

	bool operator<(const Data &data) const{
		return r < data.r;
	}
};

bool compare(Data &a, Data &b) {
	return a.year < b.year;
}

Data *tree;
void init_tree(Data *Y_arr, int n);
int b_search_index(int target, int is_X);
void search_tree(int Y, int X);
int search_max(int l, int r);
int n;
int leaf_count = 1;
int leaf_pointer;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	Data *Y_arr = new Data[n];
	for (int i = 0; i < n; i++) {
		int y, r;
		cin >> y >> r;
		Y_arr[i].year = y;
		Y_arr[i].r = r;
	}
	init_tree(Y_arr, n);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int X, Y;
		cin >> Y >> X;
		search_tree(Y, X);
	}
}

void init_tree(Data *Y_arr, int n) {
	while (n > leaf_count) {
		leaf_count *= 2;
	}
	tree = new Data[leaf_count*2];
	leaf_pointer = leaf_count;
	int idx = 0;
	for (; idx < n; idx++) {
		tree[leaf_pointer + idx] = Y_arr[idx];
	}
	// 입력값이 leaf 노드 개수보다 작은 경우 생각하기
	for (; idx < leaf_count; idx++) {
		tree[leaf_pointer + idx].year = 1000000001;
		tree[leaf_pointer + idx].r = 0;
	}
	for (int i = leaf_count - 1; i > 0; i--) {
		tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
	}

	/*for (int i = 1; i < leaf_count*2; i *= 2) {
		for (int j = i; j < i * 2; j++) {
			cout << tree[j].r << " ";
		}
		cout << "\n";
	}*/
}

int b_search_index(int target, int is_X) { // 해시맵을 사용해서 X, Y연도가 있는지 없는지 찾는 방법도 있음
	int l = leaf_pointer;
	int r = leaf_pointer+n-1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (tree[mid].year == target) {
			return mid;
		}
		else if (tree[mid].year < target) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	if (is_X == 1) {
		/*if (r < leaf_pointer) {
			return leaf_pointer;
		}*/
		return r;
	}
	else {
		/*if (l > leaf_pointer + n - 1) {
			return leaf_pointer + n - 1;
		}*/
		return l;
	}
}


void search_tree(int Y, int X) {
	int Y_index = b_search_index(Y, 0);
	int X_index = b_search_index(X, 1);
	
	if (tree[Y_index].year != Y && tree[X_index].year != X) {
		cout << "maybe\n";
		return;
	}
	else if (tree[X_index].year != X && tree[Y_index].year == Y) {
		int between_max = search_max(Y_index + 1, X_index);
		if (between_max < tree[Y_index].r) {
			cout << "maybe\n";
			return;
		}
		else {
			cout << "false\n";
			return;
		}
	}
	else if (tree[Y_index].year != Y && tree[X_index].year == X) {
		int between_max = search_max(Y_index, X_index - 1);
		if (between_max < tree[X_index].r) {
			cout << "maybe\n";
			return;
		}
		else {
			cout << "false\n";
			return;
		}
	}
	else {
		int between_max = search_max(Y_index + 1, X_index - 1);
		if ((tree[Y_index].r < tree[X_index].r) || (between_max >= tree[Y_index].r) || (between_max >= tree[X_index].r)) {
			cout << "false\n";
			return;
		}
		else if (X - Y == X_index - Y_index) {
			cout << "true\n";
			return;
		}
		else {
			cout << "maybe\n";
			return;
		}
	}
	return;
}

int search_max(int l, int r) {
	int max_r = 0;
	while (l <= r) {
		if (l % 2 == 1) {
			max_r = max(max_r, tree[l].r);
			l++;
		}
		if (r % 2 == 0) {
			max_r = max(max_r, tree[r].r);
			r--;
		}
		l /= 2;
		r /= 2;
	}
	return max_r;
}