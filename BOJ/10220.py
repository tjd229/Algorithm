#math
for _ in range(int(input())):
    N=int(input())
    cnt=0;
    if N==4:
        cnt=2
    elif N==5:
        cnt=1
    elif N>6:
        cnt=1
    print(cnt)