#include <stdio.h>
#include <algorithm>
using namespace std;
int A[1000];
int B[1000];

int main(void) {
	int T;
	scanf("%d", &T);
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %d", &A[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf(" %d", &B[i]);
	}
	long long* partial_sum_A = new long long[n*(n + 1) / 2];
	long long* partial_sum_B = new long long[m*(m + 1) / 2];
	int index = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += A[j];
			partial_sum_A[index++] = sum;
		}
	}
	index = 0;
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = i; j < m; j++) {
			sum += B[j];
			partial_sum_B[index++] = sum;
		}
	}
	sort(partial_sum_A, partial_sum_A + n * (n + 1) / 2);
	sort(partial_sum_B, partial_sum_B + m * (m + 1) / 2);
	int a_val;
	long long total_count = 0;
	for (int i = 0; i < n * (n + 1) / 2; i++) {
		a_val = partial_sum_A[i];
		int a_ub = (int)(upper_bound(partial_sum_A, partial_sum_A + n * (n + 1) / 2, a_val) - partial_sum_A);
		int a_lb = (int)(lower_bound(partial_sum_A, partial_sum_A + n * (n + 1) / 2, a_val) - partial_sum_A);
		i = a_ub-1;
		int a_count = a_ub - a_lb;
		int target_B = T - a_val;
		int b_ub = (int)(upper_bound(partial_sum_B, partial_sum_B + m * (m + 1) / 2, target_B) - partial_sum_B);
		int b_lb = (int)(lower_bound(partial_sum_B, partial_sum_B + m * (m + 1) / 2, target_B) - partial_sum_B);
		if (b_lb < m * (m + 1) / 2 && partial_sum_B[b_lb] == target_B) {
			total_count += (long long)(a_count) * (b_ub-b_lb);
		}
	}
	printf("%lld", total_count);


	return 0;
}