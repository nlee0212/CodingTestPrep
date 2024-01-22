import sys

def input():
    return sys.stdin.readline().rstrip()

N, M = map(int,input().split(' '))

def find(child):
    if parent[child] == child:
        return child
    else:
        p = find(parent[child])
        parent[child] = p
        return p

def update(c1,c2):
    p1, p2 = find(c1), find(c2)
    
    if p1 < p2:
        parent[p2] = p1

    else:
        parent[p1] = p2
        
parent = [i for i in range(N)]
for m in range(M):
    n1, n2 = map(int,input().split(' '))

    p1, p2 = find(n1), find(n2)

    if p1 != p2:
        update(n1,n2)

    else:
        print(m+1)
        exit()

print(0)

