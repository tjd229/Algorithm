#math
import sys
def ask(*args):
    print('? %d %d %d %d'%(args))
    sys.stdout.flush()
    return int(input())

T=int(input())
for _ in range(T):
    n=int(input())
    a=[0]*(n+1)
    p=[0]*(n+1)


    for i in range(1,n+1,2):
        if i==n: #odd case
            peak_pos=n
            break
        peak=ask(1,i,i+1,n-1)

        if peak==n-1:
            peak=ask(1,i+1,i,n-1)
            if peak==n:
                peak_pos=i
                break
        elif peak==n:
            q=ask(2,i,i+1,n-1)
            peak_pos=i if q==n else i+1
            break
    for i in range(1,n+1):
        if i==peak_pos:
            continue
        p[i]=ask(2,i,peak_pos,1)
    p[peak_pos] = n
    print('!')
    for i in range(1,n+1):
        print(' ',p[i])
    sys.stdout.flush()







