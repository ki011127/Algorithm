import sys
N,M = input().split()
N= int(N)
M = int(M)
sys.setrecursionlimit(10**6)
campus = []
x = 0
y = 0
count = 0

for i in range(N):
    campus.append(input())

visited = [[False]*M for _ in range(N)]
dx = [-1,1,0,0]
dy = [0,0,-1,1]

def dfs(x,y):
    global count
    visited[x][y]=True
    if campus[x][y] == 'P':
        count+=1
    for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]
        if 0<=nx<N and 0<=ny<M and visited[nx][ny]==False and campus[x][y]!='X':
            dfs(nx,ny)
for i in range(N):
    for j in range(M):
        if campus[i][j]=='I':
            dfs(i,j)

if count == 0:
    print("TT")
else:
    print(count)
