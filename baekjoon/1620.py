import sys

def input():
    return sys.stdin.readline().rstrip()

N, M = tuple(map(int,input().split(' ')))
n2id = {}
id2n = {}

for i in range(N):
    name = input()
    n2id[name] = i+1
    id2n[i+1] = name

for i in range(M):
    q = input()
    if q.isdigit():
        print(id2n[int(q)])
    else:
        print(n2id[q])