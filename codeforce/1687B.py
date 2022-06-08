#graph, MST, greedy
import sys
 
def qry(s):
    print("?",s)
    sys.stdout.flush()
    return int(input())
 
n,m = list(map(int,input().split()))
 
s=['0']*m
l=[]
for i in range(m):
    s[i]='1'
    cap = qry(''.join(s))
    l.append( (cap,i))
    s[i]='0'
l.sort()
L=0
for cap,i in l:
    s[i]='1'
    mx = qry(''.join(s))
    if L+cap ==mx:
        L=mx
    else:
        s[i]='0'
 
print("!",L)
sys.stdout.flush()