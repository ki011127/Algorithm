import sys

n, k = input().split()

n = int(n)
k = int(k)

coin = []

for i in range(n):
    coin.append(int(sys.stdin.readline().strip()))

count = 0
while k!=0:
    if(coin[n-1]<=k):
        count += k // coin[n-1]
        k = k % coin[n-1]
        
    n-=1

print(count)
