import sys

M, N = input().split()
M = int(M)
N = int(N)
d = {}
for i in range(M):
    domain, pw = sys.stdin.readline().strip().split()
    d[domain] = pw

for j in range(N):
    q = sys.stdin.readline().strip()
    print(d[q])