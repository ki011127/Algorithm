#include <stdio.h>

using namespace std;
int *tree;
void init_tree();
void update_tree(int idx, int count);
void search_tree(int rank);
int N = 1000000;
int leaf_count = 2;
int leaf_pointer;
int main(void) {
	init_tree();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b;
			scanf("%d", &b);
			search_tree(b);
		}
		else if (a == 2) {
			int b, c;
			scanf("%d %d", &b, &c);
			update_tree(b+leaf_count-1, c);
		}
	}
}

void init_tree() {
	while (N > leaf_count) {
		leaf_count *= 2;
	}
	leaf_pointer = leaf_count;
	tree = new int[leaf_count * 2];
	for (int i = 0; i < leaf_count * 2; i++) {
		tree[i] = 0;
	}
}

void update_tree(int idx, int count) {
	tree[idx] += count;
	//printf("idx: %d, tree:%d\n", idx, tree[idx]);
	idx /= 2;
	while (idx > 0) {
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		//printf("idx: %d, tree:%d\n", idx, tree[idx]);
		idx /= 2;
	}
}

void search_tree(int rank) {
	int idx = 1;
	while (leaf_pointer > idx) {
		int l_val = tree[idx * 2];
		int r_val = tree[idx * 2 + 1];
		if (rank <= l_val) {
			idx *= 2;
		}
		else {
			rank -= l_val;
			idx = idx * 2 + 1;
		}
	}
	printf("%d\n", idx-leaf_count+1);
	update_tree(idx, -1);
}