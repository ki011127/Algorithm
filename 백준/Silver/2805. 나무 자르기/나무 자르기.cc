#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	long long M;
	scanf("%d %lld", &N, &M);
	int *trees = new int[N];
	int max_cut_height = 0;
	for (int i = 0; i < N; i++) {
		scanf(" %d", &trees[i]);
		if (trees[i] > max_cut_height) {
			max_cut_height = trees[i];
		}
	}
	int min_cut_height = 0;
	int cut_height;
	int ans = 0;
	while (min_cut_height <= max_cut_height) {
		long long sum = 0;
		cut_height = (max_cut_height + min_cut_height) / 2;
		for (int i = 0; i < N; i++) {
			int h = trees[i] - cut_height;
			if (h > 0) {
				sum += (long long)h;
			}
		}
		if (sum >= M) {
			min_cut_height = cut_height + 1;
			if (ans < cut_height) {
				ans = cut_height;
			}
		}
		else {
			max_cut_height = cut_height - 1;
		}
	}
	printf("%d", ans);
	return 0;
}
