import heapq
import sys

heap = []
N = int(input())
for i in range(N):
    x = int(sys.stdin.readline().strip())
    result  =0
    if x == 0:
        if len(heap):
            print(heapq.heappop(heap))
        else :
            print(0)
    else:
        heapq.heappush(heap,x)
