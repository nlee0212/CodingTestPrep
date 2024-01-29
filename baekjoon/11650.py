import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
res = []

for i in range(N):
    x, y = map(int,input().split(' '))

    res.append((x,y))

res = sorted(res)

for r in res:
    print(r[0],r[1])