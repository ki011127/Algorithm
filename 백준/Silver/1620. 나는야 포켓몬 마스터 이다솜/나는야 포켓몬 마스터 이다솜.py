import sys

num1, num2 = input().split()
num1 = int(num1)
num2 = int(num2)
pok_list = {}
dict = {}
for i in range(num1):
    pok_name = sys.stdin.readline().strip()
    pok_list[i] = pok_name
    dict[pok_name] = i+1

for i in range(num2):
    quiz = sys.stdin.readline().strip()
    if quiz.isdigit():
        print(pok_list[int(quiz)-1])
    else:
        print(dict[quiz])