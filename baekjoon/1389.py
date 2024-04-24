import sys
from collections import defaultdict,deque


def input():
    return sys.stdin.readline().rstrip()

friends = defaultdict(set)

N,M = map(int,input().split(' '))

for m in range(M):
    a,b = map(int,input().split(' '))
    friends[a].add(b)
    friends[b].add(a)
    
for n in range(1,N+1):
    friends[n] = list(friends[n])

min_bacon = float('inf')
min_bacon_num = -1

for n in range(1,N+1):
    queue = deque()
    queue.append((n,0))
    visited = [0]*(N+1)
    
    while queue:
        friend,step = queue.popleft()
        if visited[friend] == 0:
            if step:
                visited[friend] = step
            else:
                visited[friend] = 1
                
            for f in friends[friend]:
                if not visited[f]:
                    queue.append((f,step+1))
    visited[n] = 0
    # print(visited)
    res = sum(visited)
    if res < min_bacon:
        min_bacon = res
        min_bacon_num = n

print(min_bacon_num)    