import sys

def input():
    return sys.stdin.readline().rstrip()

T = int(input())

for t in range(T):
    N = int(input())
    logs = list(map(int,input().split(' ')))
    
    logs.sort()
    max_lev = 0
    
    if N % 2 == 0:
        max_lev = max(max_lev,logs[1]-logs[0])
        max_lev = max(max_lev,logs[2]-logs[0])
        
        logs = logs[1:]
        N -= 1
        
    for i in range(N-2):
        max_lev = max(max_lev,logs[i+2]-logs[i])
    max_lev = max(max_lev,logs[N-1]-logs[N-2])
    
    print(max_lev)