str = input()

num = []
p_m = []
index = 0
for i in range(len(str)):
    if str[i]=='-' or str[i]=='+':
        num.append(int(str[index:i]))
        index=i+1
        p_m.append(str[i])
num.append(int(str[index:]))
result = [num[0],]
flag = 0
cac = 0
for i in range(len(p_m)):
    if p_m[i] == '-':
        if flag==0 :
            result.append(cac)
        else :
            result.append(-cac)
        flag=1
        cac = num[i+1]
    else :
        cac+=num[i+1]
if flag ==0 :
    result.append(cac)
else :
    result.append(-cac)
print(sum(result))     