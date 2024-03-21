import sys
from collections import deque

n, m, v = input().split()
n = int(n)
m = int(m)
v = int(v)

is_dfs_visit = [0] * (n+1)
is_bfs_visit = [0] * (n+1)

is_dfs_visit[v] = 1
is_bfs_visit[v] = 1
table = [[0 for j in range(n+1)] for i in range(n+1)]

for i in range(m):
    x, y = sys.stdin.readline().strip().split()
    x = int(x)
    y = int(y)
    table[x][y] = 1
    table[y][x] = 1

count = 0
cur = v

def dfs(v):
    is_dfs_visit[v] = 1
    print(v, end=' ')
    for i in range(1, n+1):
        if(table[v][i]==1 and is_dfs_visit[i] == 0):
            dfs(i)

dfs(v)
print()
def bfs(v):
    q = deque([v])
    is_bfs_visit[v] = 1
    while q:
        v = q.popleft()
        print(v, end=' ')
        for i in range(1, n+1):
            if(table[v][i]==1 and is_bfs_visit[i]==0):
                q.append(i)
                is_bfs_visit[i] = 1

bfs(v)