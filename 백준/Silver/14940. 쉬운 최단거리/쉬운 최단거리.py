import sys
from collections import deque
N,M = input().split()
N = int(N)
M = int(M)
directionX = [1,0,-1,0]
directionY = [0,1,0,-1]
g = [[0 for j in range(M)] for i in range(N)]
length = [[0 for j in range(M)] for i in range(N)]
visit = [[0 for j in range(M)] for i in range(N)]
for i in range(N):
    g[i]=list(map(int,sys.stdin.readline().strip().split()))
for i in range(N):
    for j in range(M):
        if(g[i][j]==2):
            visit[i][j] = 1
            q = deque([(i,j)])
            break
l = 0
while q:
    x,y = q.popleft()
    for i in range(4):
        nx = x+directionX[i]
        ny = y+directionY[i]
        if nx < 0 or ny < 0 or nx >= N or ny >= M:
            continue 
        if g[nx][ny]==1 and visit[nx][ny]==0:
            length[nx][ny] = length[x][y]+1
            visit[nx][ny] = 1
            q.append((nx,ny))

for i in range(N):
    for j in range(M):
        if visit[i][j]==1 and length[i][j]>=0:
            print(length[i][j], end=' ')
        elif visit[i][j]==0 and g[i][j]==0:
            print("0", end=' ')
        elif visit[i][j]==0 and g[i][j]==1:
            print("-1", end=' ')
    print()