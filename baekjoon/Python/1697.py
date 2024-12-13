import sys
from collections import defaultdict, deque
# import deque

# sys.setrecursionlimit(1000000)

def input():
    return sys.stdin.readline().rstrip()

N, K = map(int,input().split(' '))

visited = [0]*100001
    
queue = deque([N])

while queue:
    cur = queue.popleft()

    if cur == K:
        print(visited[cur])
        exit()

    for next_loc in (cur+1,cur-1,cur*2):
        if 0<=next_loc<=100000 and not visited[next_loc]:
            visited[next_loc] = visited[cur]+1
            queue.append(next_loc) 

    