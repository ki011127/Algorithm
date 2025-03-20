#include <stdio.h>

using namespace std;
long long *tree;
void init_tree(int N);
int leaf_pointer;
int leaf_count = 2;
void update_tree(int index, long long value);
long long sum_tree(int b, int c);
int main(void) {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	init_tree(N);
	int idx = 0;
	for (; idx < N; idx++) {
		//printf("leaf : %d\n", leaf_pointer);
		scanf("%lld", &tree[leaf_pointer++]);
	}
	for (; idx < leaf_count; idx++) {
		tree[leaf_pointer++] = 0;
	}

	for (int j = leaf_count - 1; j > 0; j--) {
		//printf("j: %d, %lld\n", j,tree[j * 2] + tree[j * 2 + 1]);
		tree[j] = tree[j * 2] + tree[j * 2 + 1];
	}

	/*for (int i = 1; i < leaf_count*2 - 1; i *= 2) {
		for (int j = i; j < i * 2; j++) {
			printf("%lld ", tree[j]);
		}
		printf("\n");
	}*/
	for (int i = 0; i < M + K; i++) {
		int a, b;
		long long c;
		scanf("%d %d %lld", &a, &b, &c);
		if (a == 1) {
			update_tree(b, c);
		}
		else if (a == 2) {
			long long result = sum_tree(b, c);
			printf("%lld\n", result);
		}
	}

}

void init_tree(int N) {
	while (N > leaf_count) {
		leaf_count *= 2;
	}
	tree = new long long[leaf_count*2];
	leaf_pointer = leaf_count;
}

void update_tree(int index, long long value) {
	int i = index + leaf_count - 1;
	tree[i] = value;
	i /= 2;
	while (i > 0) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
		i /= 2;
	}
}

long long sum_tree(int b, int c) {
	int l = leaf_count + b - 1;
	int r = leaf_count + c - 1;
	long long sum = 0;
	while (l <= r) {
		if (l % 2 != 0) {
			sum += tree[l];
			l++;
		}
		if (r % 2 == 0) {
			sum += tree[r];
			r--;
		}
		l /= 2;
		r /= 2;
	}
	return sum;
}

