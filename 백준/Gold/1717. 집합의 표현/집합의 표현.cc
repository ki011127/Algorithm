#include <iostream>

using namespace std;
int s[1000001];
void uni(int a, int b);
int find(int a);
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		s[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int v, a, b;
		cin >> v >> a >> b;
		if (v == 0) {
			uni(a, b);
		}
		else if (v == 1) {
			if (find(a) == find(b)) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
	}
	return 0;
}

void uni(int a, int b) {
	int a_root = find(a);
	int b_root = find(b);
	if (a_root != b_root) {
		s[b_root] = a_root;
	}
}

int find(int a) {
	if (s[a] == a) {
		return a;
	}
	else {
		return s[a] = find(s[a]);
	}
}