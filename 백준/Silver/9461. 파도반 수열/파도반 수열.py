T = int(input())

P = [0,1,1,1,2,2,3,4,5,7,9]

for i in range(T):
    N = int(input())
    if len(P)>=N+1:
        print(P[N])
    else:
        j = len(P)-1
        while j!=N:
            P.append(P[j]+P[j-4])
            j+=1
        print(P[N])
