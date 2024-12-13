import sys
from collections import defaultdict

def input():
    return sys.stdin.readline().rstrip()

N,M = map(int,input().split(' '))

edges = defaultdict(dict)

for n in range(N-1):
    a,b,cost = map(int,input().split(' '))
    edges[a][b] = cost
    edges[b][a] = cost

# print(edges)

def dfs(visited,cur,target):
    visited[cur] = 1
    total_len = 0
    # print(cur,target)
    for v in edges[cur]:
        if not visited[v]:
            if v == target:
                return edges[cur][v]
            else:
                res = dfs(visited,v,target) 
                # total_len += dfs(visited,v,target)
                if res > 0:
                    return res + edges[cur][v]
    return 0
    
for m in range(M):
    visited = [0]*(N+1)
    a,b = map(int,input().split(' '))
    total = dfs(visited,a,b)
    print(total)