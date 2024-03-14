import sys
import heapq
from collections import defaultdict

def input():
    return sys.stdin.readline().rstrip()

T = int(input())

for t in range(T):
    n,d,c = map(int,input().split(' '))
    
    graph = defaultdict(dict)    
    
    total_cost = [float('inf') for i in range(n+1)]
    total_cost[c] = 0
    
    pq = [] # (dist,node_num)
    
    for i in range(d):
        a,b,s = map(int,input().split(' '))
        
        graph[b][a] = s
        
    heapq.heappush(pq,(0,c))
    # print(graph)
    while pq:
        # print(pq)
        dist, node = heapq.heappop(pq)
        # print(total_cost)
        # print(dist,total_cost[node])
        if dist != total_cost[node]:
            continue
        # print(node,graph[node])
        for k,v in graph[node].items():
            # print(k,v)
            if total_cost[k] > dist + v:
                total_cost[k] = dist + v
                heapq.heappush(pq,(total_cost[k],k))
                # print(total_cost)
    
    cnt = 1
    max_time = 0
    for i,cost in enumerate(total_cost):
        if i != c and cost != float('inf'):
            cnt += 1
            if max_time < cost:
                max_time = cost
    print(cnt,max_time)