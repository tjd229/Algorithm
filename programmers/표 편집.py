#https://programmers.co.kr/learn/courses/30/lessons/81303
#implementation
def solution(n, k, cmd):
    answer = ['O']*n
    l,r=list(range(-1,n-1)), list(range(1,n))
    r.append(-1)
    cur=k
    stk=[]

    for inp in cmd:
        if inp[0]=='U':
            mv=int(inp[2:])
            for _ in range(mv):
                cur=l[cur]
        elif inp[0]=='D':
            mv=int(inp[2:])
            for _ in range(mv):
                cur=r[cur]
        elif inp[0]=='C':
            answer[cur]='X'
            if r[cur]!=-1:
                right=r[cur]
                l[right]=l[cur]
            if l[cur]!=-1:
                left=l[cur]
                r[left]=r[cur]
            stk.append(cur)
            cur = r[cur] if r[cur]!=-1 else l[cur]
        else:
            x=stk.pop()
            if r[x]!=-1:
                right=r[x]
                l[right]=x
            if l[x]!=-1:
                left=l[x]
                r[left]=x
            answer[x] = 'O'

    return "".join(answer)


