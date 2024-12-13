import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
expected = []

for  n in range(N):
    expected.append(int(input()))
    
expected.sort()

unsatis = 0
for i,e in enumerate(expected):
    unsatis += abs(e-(i+1))
    
print(unsatis)