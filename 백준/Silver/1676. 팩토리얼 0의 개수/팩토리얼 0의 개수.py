n = int(input())
ft = 1
while n>0:
    ft*=n
    n-=1

ft_list = list(str(ft))
count = 0
ft_list.reverse()
for ch in ft_list:
    if(ch!='0'):
        print(count)
        break
    else:
        count+=1