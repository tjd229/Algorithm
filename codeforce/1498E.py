#graph, SCC
import sys
n=int(input())
k=list(map(int,input().split()))
 
order=[ (ind,x) for x,ind in enumerate(k) ]
order=sorted(order)
 
mx=-1
A=B=-1
cum=0
src=0
for i,(ind,x) in enumerate(order):
    cum+=ind
    if cum==((i+1)*i)//2:
        if src!=i:
            d=abs(order[src][0]-order[i][0])
            if d>mx:
                mx=d
                A,B=order[src][1],order[i][1]
        src=1+i #next SCC
print("! %d %d"%(A+1,B+1))
sys.stdout.flush()