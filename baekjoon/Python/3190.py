import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

K = int(input())

visited = [[0 for _ in range(N)] for _ in range(N)]
visited[0][0] = 1

apples = []
for k in range(K):
    ai,aj = map(int,input().split(' '))
    visited[ai-1][aj-1] = -1
    
L = int(input())
changes = []
for l in range(L):
    x,c = input().split(' ')
    changes.append((int(x),c))
    
sec = 1
direction = deque([(0,1),(1,0),(0,-1),(-1,0)])
cur_i,cur_j = 0,0
snake = deque([(cur_i,cur_j)])

while True:
    di,dj = direction[0]
    newi,newj = cur_i+di,cur_j+dj
    
    if 0<=newi<N and 0<=newj<N and visited[newi][newj] != 1:
        snake.append((newi,newj))
        if visited[newi][newj] != -1:
            tail_i,tail_j = snake.popleft()
            visited[tail_i][tail_j] = 0
        visited[newi][newj] = 1
    else:
        print(sec)
        break
    
    # for row in visited:
    #     print(row)
    # print()    

    if changes and sec == changes[0][0]:
        if changes[0][1] == 'D':
            direction.rotate(-1)
        else:
            direction.rotate(1)
        changes = changes[1:]
    sec += 1
    cur_i,cur_j = newi,newj
    
    