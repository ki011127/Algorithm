from collections import deque
n, k = map(int,input().split())


q = deque([n])
max = 100001
dst = [0]*100001
while q:
    a = q.popleft()
    if a == k:
        print(dst[a])
        break
    for i in (a-1, a+1, a*2):
        if 0 <= i and i < max and dst[i]==0:
            q.append(i)
            dst[i] = dst[a]+1
