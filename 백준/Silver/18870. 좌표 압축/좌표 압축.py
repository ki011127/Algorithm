N = int(input())

s = list(map(int, input().split()))
l = set(s)

l = list(l)

l = sorted(l)
result = {}
for i in range(len(l)):
    result[l[i]] = i
for i in range(len(s)):
    print(result[s[i]], end=" ")