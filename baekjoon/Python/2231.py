import sys
import heapq
import re

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

for i  in range(1,N):
    if i + sum([int(c) for c in  str(i)]) == N:
        print(i)
        break
    
else:
    print(0)