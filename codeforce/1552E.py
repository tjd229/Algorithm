#greedy
import math
n,k=list(map(int, input().split()))
a,b=[0]*(n+1),[0]*(n+1)

c=[ [] for _ in range(1+n) ]

nk=n*k
mxcnt=math.ceil(n/(k-1))

for i,clr in enumerate( list(map(int, input().split())) ):
    c[clr].append(i+1)

it=[ [] for _ in range(k) ]

for i in range(1,1+n):
    for j in range(1,k):
        it[j].append( (c[i][j], c[i][j-1], i) )

remain=n
step=1

while remain>0:
    cnt=0
    for e,s,clr in sorted(it[step]):
        if a[clr]>0:
            continue
        a[clr],b[clr]=s,e
        cnt+=1
        remain-=1
        if cnt==mxcnt:
            break
    step+=1

for i in range(1,n+1):
    print("%d %d\n"%(a[i],b[i]))


