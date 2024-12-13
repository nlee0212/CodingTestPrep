import sys
from collections import defaultdict
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N, M = map(int,input().split(' '))

bridges = defaultdict(list)
max_nodes = dict()
start = 1000000000
end = 1

for i in range(M):
    A, B, C = map(int,input().split(' '))
    start = min(start,C)
    end = max(end,C)

    bridges[A].append((B,C))
    bridges[B].append((A,C))

A,B = map(int,input().split(' '))

res = 0

while start <= end:
    mid = (start + end)//2

    visited = {A}
    queue = deque([A])
    found = False

    # print(mid)
    while queue:
        # print(queue)
        # print(visited)
        
        cur = queue.popleft()
        # print(cur)
        
        for node,weight in bridges[cur]:
            if node not in visited and weight >= mid:
                visited.add(node)
                queue.append(node)
    if B in visited:
        res = mid
        start = mid + 1
    else:
        end = mid - 1

print(res)