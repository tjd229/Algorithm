#bs
import sys

def qry(w):
    print("?",w)
    sys.stdout.flush()
    return int(input())

n = int(input())


l,r=1,2000*n+n-1
area = r
while l<=r:
    m=(l+r)//2
    h = qry(m)
    if h==1:
        area=min(area,m)
        r=m-1
    else:
        l=m+1

for i in range(2,n+1):
    w=area//i
    h=qry(w)
    if h==0:
        break
    area=min(area, h*w)

print("!",area)
sys.stdout.flush()

