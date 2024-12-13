import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

A = list(map(int,input().split(' ')))
B = list(map(int,input().split(' ')))

A.sort()
B.sort(reverse=True)

S = 0
for a,b in zip(A,B):
    S += a*b
    
print(S)