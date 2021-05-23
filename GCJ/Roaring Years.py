#https://codingcompetitions.withgoogle.com/codejam/round/00000000004362d7/00000000007c0f01
#math, greedy
def fact(x, v):
    while x>0:
        v.append(x%10)
        x//=10
    v.reverse()
def roar(base,sz):
    v=[]
    coin=0
    while coin<2 or len(v)<sz:
        sub=[]
        fact(base,sub)
        v.extend(sub)
        base+=1
        coin+=1
        
    z=0
    for x in v:
        z=z*10+x
    return z

for x in range(int(input())):
    Y=int(input())
    if Y<12:
        z=12
    else:
        v=[]
        fact(Y,v)
        
        
        z=roar(1,1+len(v))

        base=1
        for _ in range(len(v)):
            base*=10
            zz=roar(base,1+len(v))
            z=min(z,zz)
        base=10
        while base<=Y:
            for pad in range(19):
                if base-pad<=0:
                    break
                zz=roar(base-pad,len(v))
                if zz>Y:
                    z=min(zz,z)
            base*=10
        base=0
        sz=1
        for b in v:
            base=base*10+b
            zz = roar(base,len(v))
            if zz>Y:
                z=min(z,zz)
            add=1
            for _ in range(sz+1):
                for m in range(10):
                    new_base=base+add*m
                    new_base//=add
                    new_base*=add
                    zz=roar(new_base,len(v))
                    if zz>Y:
                        z=min(z,zz)
                add*=10
            sz+=1
    print(f"Case #{x+1}: {z}")
            
    