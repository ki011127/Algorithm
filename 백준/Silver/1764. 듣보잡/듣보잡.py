import sys

a, b = input().split()

a= int(a)
b=int(b)

d = {}
n = []
for i in range (a):
    name = sys.stdin.readline().strip()
    d[name]=1
count = 0
for i in range(b):
    name = sys.stdin.readline().strip()
    if 1 == d.get(name):
        n.append(name)
        count+=1
        
n.sort()

print(count)
for i in range(len(n)):
    print(n[i])