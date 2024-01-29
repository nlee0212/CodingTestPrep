import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
res = {}

for i in range(N):
    num = int(input())
    # res.append(num)
    res[num] = res.get(num,0)+1

res = sorted(res.items())

for r,cnt in res:
    for i in range(cnt):
        print(r)