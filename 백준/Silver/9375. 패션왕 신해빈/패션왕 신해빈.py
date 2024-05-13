n = int(input())

for i in range(n):
    dict = {}
    m = int(input())
    for j in range(m):
        value, key = input().split(' ')
        if key in dict:
            dict[key] = dict[key]+1
        else:
            dict[key] = 1
    answer = 1
    for key in dict.keys():
        answer = answer*(dict[key]+1)
    print(answer-1)