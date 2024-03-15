import sys
import heapq
from collections import defaultdict,deque
 

# from collections import defaultdict
sys.setrecursionlimit(1000000)

def input():
    return sys.stdin.readline().rstrip()

while True:
    
    N,M = map(int,input().split(' '))
    if N == 0 and M == 0:
        break
    
    roads = defaultdict(dict)
    reverse_roads = defaultdict(dict)
    dropped = defaultdict(dict)
    
    S,D = map(int,input().split(' '))
    cost_path = [float('inf') for _ in range(N)]
    # before_path = [set() for _ in range(N)]
    
    cost_path[S] = 0
    pq = [(0,S)]
    
    for m in range(M):
        U,V,P = map(int,input().split(' '))
        roads[U][V] = P
        reverse_roads[V][U] = P
        # dropped[U][V] = False
    # print(roads)
    # print(pq)
    
    while pq:
        # print(pq)
        
        cost,u = heapq.heappop(pq)
        # print(u,cost)
        if cost != cost_path[u]:
            continue
                
        for v,dist in roads[u].items():
            # print(v,dist)
            if cost_path[v] > cost+dist:
                cost_path[v] = cost+dist
                heapq.heappush(pq,(cost_path[v],v))
            #     before_path[v] = set([u])
                
            # elif cost_path[v] == cost + dist:
            #     before_path[v].add(u)
                
                
    # print(cost_path)
    # print(before_path)
    
    # print(roads)
    q = deque([D])
    while q:
        popped = q.popleft()
        
        for adj,dist in reverse_roads[popped].items():
            if popped in roads[adj]:
                if cost_path[popped] == cost_path[adj]+dist:
                    # print(adj,popped)
                    del roads[adj][popped]
                    q.append(adj)
                
            
    # print(roads)
    
    cost_path = [float('inf') for _ in range(N)]
    cost_path[S] = 0
    pq = [(0,S)]

    while pq:
        # print(pq)
        
        cost,u = heapq.heappop(pq)
        # print(u,cost)
        if cost != cost_path[u]:
            continue
                
        for v,dist in roads[u].items():
            # print(v,dist)
            if cost_path[v] > cost+dist:
                cost_path[v] = cost+dist
                heapq.heappush(pq,(cost_path[v],v))

    # print(cost_path)
    if cost_path[D] == float('inf'):
        print(-1)
    else:
        print(cost_path[D])