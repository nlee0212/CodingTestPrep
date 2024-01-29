import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
res = []

for i in range(N):
    num, name = input().split(' ')
    num = int(num)

    res.append((num,i,name))

res = sorted(res)

for r in res:
    print(r[0],r[2])