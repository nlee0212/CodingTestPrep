import sys

def input():
    return sys.stdin.readline().rstrip()

N, M = map(int,input().split())

parent = [0]+[i+1 for i in range(N)]

def find(child):
    if parent[child] == child:
        return child
    else:
        p = find(parent[child])
        parent[child] = p
        return p

def union(c1,c2):
    p1, p2 = find(c1),find(c2)

    if p1 < p2:
        parent[p2] = p1
    else:
        parent[p1] = p2

for i in range(M):
    c1,c2 = map(int,input().split())
    p1, p2 = find(c1),find(c2)

    union(c1,c2)

for i in range(N,0,-1):
    find(i)

print(len(set(parent))-1)