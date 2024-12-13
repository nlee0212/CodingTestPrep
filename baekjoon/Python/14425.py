import sys

def input():
    return sys.stdin.readline().rstrip()

N,M = tuple(map(int,input().split(' ')))

S = set()

for i in range(N):
    S.add(input())

res = 0
for i in range(M):
    e = input()
    if e in S:
        res += 1

print(res)