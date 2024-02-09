import sys
import heapq
from collections import deque,defaultdict

def input():
    return sys.stdin.readline().rstrip()

N, M = map(int,input().split(' '))

degree_dict = dict()
level_graph = defaultdict(list)

for i in range(M):
    a,b = map(int,input().split(' '))

    heapq.heappush(level_graph[a],b)
    degree_dict[b] = degree_dict.get(b,0) + 1

level_0s = list(set(range(1,N+1))-set(degree_dict))
heapq.heapify(level_0s)
result = []
while level_0s:
    popped = heapq.heappop(level_0s)
    result.append(popped)
    next_nodes = level_graph[popped]
    for v in next_nodes:
        degree_dict[v] -= 1
        if degree_dict[v] == 0:
            heapq.heappush(level_0s,v)

for r in result:
    print(r,end=' ')