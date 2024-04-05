import sys

N, M = input().split()
N = int(N)
M = int(M)


arr = list(map(int,sys.stdin.readline().strip().split()))
sum = [0, arr[0]]
for i in range(1,N):
    sum.append(sum[i]+arr[i])
for j in range(M):
    a, b = map(int,sys.stdin.readline().strip().split())
    print(sum[b]-sum[a-1])