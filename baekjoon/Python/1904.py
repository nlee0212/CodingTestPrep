import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
if N == 1:
    print(1)
    exit()

before1 = 1
before2 = 1

for i in range(2,N+1):
    cur = (before1+before2)%15746
    before1 = before2
    before2 = cur

print(cur)