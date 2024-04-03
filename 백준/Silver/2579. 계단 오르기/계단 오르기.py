import sys

N = int(input())
stair = [0]*(N+1)
dp = [[0 for j in range(N+1)] for i in range(2)]
for i in range(1,N+1):
    stair[i]=int(sys.stdin.readline().strip())
dp[0][1] = stair[1]
dp[1][1] = stair[1]

for i in range(2,N):
    dp[0][i] = max(dp[1][i-2]+stair[i],dp[0][i-2]+stair[i])
    dp[1][i] = dp[0][i-1]+stair[i]
# if N>=3:
if N==1:
    print(stair[1])
else:
    print(max(dp[0][N-1]+stair[N],dp[0][N-2]+stair[N],dp[1][N-2]+stair[N]))
