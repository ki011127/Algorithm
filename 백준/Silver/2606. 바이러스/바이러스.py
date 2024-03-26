import sys
from collections import deque

a = int(input())
b = int(input())
arr = [[0 for j in range(a+1)] for i in range(a+1)]
for i in range(b):
    c,d = sys.stdin.readline().strip().split()
    c = int(c)
    d = int(d)
    arr[c][d] = 1
    arr[d][c] = 1
queue = deque([1])
count = 0
isvisit = [0]*(a+1)
isvisit[1] = 1
while queue:
    x = queue.popleft()
    for i in range(1,a+1):
        if arr[x][i]==1 and isvisit[i]==0:
            queue.append(i)
            count+=1
            isvisit[i]=1

print(count)