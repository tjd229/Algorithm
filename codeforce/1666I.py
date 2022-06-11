#geometry, math
import sys
 
def qry(op, r, c):
    print(op,r,c)
    sys.stdout.flush()
    return int(input())
 
t = int(input())
 
for _ in range(t):
    n,m = list(map(int, input().split()))
 
    i,j = qry("SCAN",1,1),qry("SCAN",1,m)
    x12 = (i-j+2+m+m)//2
    y12 = (i+j+6-m-m)//2
    cx = qry("SCAN", 1, x12//2)
    cy = qry("SCAN", y12//2, 1)
 
    x1 = (i-cx)//2+1
    y1 = (i - cy) // 2 + 1
 
    dy = (i+j-m-m-4*y1+6)//2
    dx = i-dy-2*(y1-1)-2*(x1-1)
    x2,y2=x1+dx,y1+dy
 
    if qry("DIG",y1,x1)==1:
        qry("DIG",y2,x2)
    else:
        qry("DIG", y1, x2)
        qry("DIG", y2, x1)