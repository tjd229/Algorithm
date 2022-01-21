#math
import sys
def ask(i):
    print("? %d"%i)
    sys.stdout.flush()
    return int(input())
 
for _ in range(int(input())):
    n = int(input())
    p =[0]*(1+n)
 
    for i in range(1,n+1):
        if p[i]==0:
            perm = [ask(i), ask(i)]
            while perm[0]!=perm[-1]:
                perm.append(ask(i))
            perm.pop()
            perm.reverse()
            k =0
            while perm[k]!=i:
                k+=1
            perm.extend(perm[:k])
            for pos in perm[k:]:
                p[pos]= perm[k-1]
                k+=1
 
    print("!",*p[1:])
    sys.stdout.flush()