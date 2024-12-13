import sys

sys.setrecursionlimit(1000000)

def input():
    return sys.stdin.readline().rstrip()

N, S, M = map(int,input().split(' '))
V = list(map(int,input().split(' ')))

result = [[-100 for i in range(M+1)] for j in range(N)]

def dfs(start,idx):
    if start > M:
        return -1
    if start < 0:
        return -1
    
    if idx == N-1:
        if result[idx][start] == -100:
            if start + V[idx] <= M:
                result[idx][start] =  start + V[idx]
            elif start - V[idx] >= 0:
                result[idx][start] =  start - V[idx]
            else:
                result[idx][start] =  -1
        # else:
        #     print(idx,start)
        return result[idx][start]
    
    if result[idx][start] == -100: 
        up = dfs(start+V[idx],idx+1)
        down = dfs(start-V[idx],idx+1)
        result[idx][start] = max(up,down)
    # else:
    #     print(idx,start) 
    return result[idx][start]

print(dfs(S,0))