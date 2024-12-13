import sys
from collections import defaultdict, deque
# import deque

sys.setrecursionlimit(1000000)

def input():
    return sys.stdin.readline().rstrip()

N, M, V = map(int,input().split(' '))
edges = defaultdict(list)

for i in range(M):
    v1, v2 = map(int,input().split(' '))
    edges[v1].append(v2)
    edges[v2].append(v1)
    
for k,v in edges.items():
    edges[k] = sorted(v)
    
# edges_bfs = edges.copy()

visited = [0 for i in range(N+1)]
track = []
def dfs(start):
    # print(start,edges[start])
    if not visited[start]:
        track.append(str(start))
        visited[start] = 1
        for v in edges[start]:
            if not visited[v]:
                # print(' ',v)
                # visited[v] = 1
                # track.append(str(v))
                dfs(v)
            
dfs(V)
# track = [str(v) for v in track]
print(' '.join(track))

queue = deque([V])
visited = [0 for i in range(N+1)]
track = [str(V)]
visited[V] = 1
while queue:
    cur = queue.popleft() 
    # print(queue)

    # print(cur,edges[cur])
    for v in edges[cur]:
        if not visited[v]:
            visited[v] = 1
            track.append(str(v))
            queue.append(v)
            
print(' '.join(track))
            