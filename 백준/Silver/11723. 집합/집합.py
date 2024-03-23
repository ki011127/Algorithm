import sys

m = int(input())
s = set()

for i in range(m):
    a = sys.stdin.readline().strip().split()
    if len(a) == 2:
        x = a[0]
        b = a[1]
        b = int(b)
    else :
        x = a[0]
    if(x == 'add'):
        s.add(b)
    elif(x=='remove'):
        s.discard(b)
    elif(x=='check'):
        if(b in s):
            print(1)
        else:
            print(0)
    elif(x=='toggle'):
        if (b in s):
            s.discard(b)
        else :
            s.add(b)
    elif(x=='all'):
        s.update([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20])
    elif(x=='empty'):
        s.clear()

