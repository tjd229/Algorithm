#bs, geometry
import sys
def ask(*args):
    print("? %d %d"%(args))
    sys.stdout.flush()
    return int(input())

d1 = ask(1,1)
d2 = ask(int(1e9),1)
d3= ask(1,int(1e9))

lb = d1+1
rb = int(1e9)-d2
if lb>rb:
    cen = lb+rb
    r = cen//2
    if (cen&1)==0:
        r-=1
else:
    r=lb-1
l = 2
x=r
foot = ask(r,1)
while l<=r:
    m=(l+r)>>1
    d = ask(m,1)
    if foot == d:
        x=m
        r=m-1
    else: l=m+1

y=foot+1
p=int(1e9)+y-1-d2
q=int(1e9)+x-1-d3

print("!",x,y,p,q)
sys.stdout.flush()




