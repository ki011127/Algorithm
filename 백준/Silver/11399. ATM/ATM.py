a = int(input())
li = list(map(int, input().split()))

li.sort()

sum = li[0]
result = li[0]
#[1,2,3,3,4]
for i in range(1,len(li)):
    sum = sum + li[i]
    result+=sum
print(result)
