import sys
sys.setrecursionlimit(2000)
N, M = map(int, input().split())
graph = [[0 for i in range(N+1)]for j in range(N+1)]
visit = [0]*(N+1)
for i in range(M):
    u, v = map(int, sys.stdin.readline().strip().split())
    graph[u][v] = 1
    graph[v][u] = 1
count = 0
def dfs(n):
    for i in range(1,N+1):
        if visit[i]==0 and graph[n][i]==1 and n!=i:
            visit[i] = 1
            dfs(i)
for i in range(1, N+1):
    if visit[i]==0:
        dfs(i)
        count+=1
print(count)