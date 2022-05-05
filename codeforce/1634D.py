#math, greedy
import sys

def ask(*args):
    print("?",*args)
    sys.stdout.flush()
    return int(input())



t=int(input())
for _ in range(t):
    n = int(input())
    k=1
    while k+3<=n:
        piv = ask(k,k+1,k+2)
        vals = [ask(k+1,k+2,k+3), ask(k,k+2,k+3), ask(k,k+1,k+3)]
        mx = max(vals)
        if vals.count(piv)!=3:
            break
        k+=4
    if k==n:
        print("!",n,n)
    elif k+1==n:
        print("!",n-1,n)
    else:
        if k+2==n:
            k=k-1
            piv = ask(k, k + 1, k + 2)
            vals = [ask(k + 1, k + 2, k + 3), ask(k, k + 2, k + 3), ask(k, k + 1, k + 3)]
            mx = max(vals)

        peaks=[]
        mid = k

        for i, val in enumerate(vals):
            if mx != val:
                peaks.append(k + i)
        if len(peaks)==0:
            peaks=[k]
        if len(peaks)<2:
            peaks.append(k+3)
        if mx==piv:
            peaks=peaks[:2]
        else:
            peaks=[peaks[0], k+3]
        mid = k
        while mid in peaks:
            mid+=1
        #print(peaks)
        for i in range(k+4,n+1):
            val = ask(*peaks,i)
            if val>mx:
                mx=val
                if val==ask(peaks[1],mid,i):
                    peaks[0]=i
                else:
                    peaks[1]=i
        print("!",*peaks)
    sys.stdout.flush()

