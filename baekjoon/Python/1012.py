import sys
# from collections import defaultdict
sys.setrecursionlimit(1000000)

def input():
    return sys.stdin.readline().rstrip()

T = int(input())



for t in range(T):
    M, N, K = map(int,input().split(' '))
    
    field = [[0 for _ in range(M)] for _ in range(N)]
    visited = [[0 for _ in range(M)] for _ in range(N)]
    locs = set()
    
    def dfs(r,c):
        # print(' ',r,c)
        if c+1<M and not visited[r][c+1] and field[r][c+1]:
            visited[r][c+1] = 1
            dfs(r,c+1)
        if c-1>=0 and not visited[r][c-1] and field[r][c-1]:
            visited[r][c-1] = 1
            dfs(r,c-1)
        if r+1<N and not visited[r+1][c] and field[r+1][c]:
            visited[r+1][c] = 1
            dfs(r+1,c)
        if r-1>=0 and not visited[r-1][c] and field[r-1][c]:
            visited[r-1][c] = 1
            dfs(r-1,c)
            
    for k in range(K):
        c,r = map(int,input().split(' '))
        field[r][c] = 1
        locs.add((r,c))
    
    group_num = 0
    for r,c in locs:
        if not visited[r][c]:
            group_num += 1
            visited[r][c] = 1
            dfs(r,c)
    print(group_num)
    