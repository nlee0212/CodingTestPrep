import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

square = []
for n in range(N):
    square.append(list(map(int,input().split())))
    
queue = deque([square])
white = 0
blue = 0

while queue:
    popped = queue.popleft()
    
    sum_squares = sum([sum(row) for row in popped])
    
    if sum_squares not in [len(popped)**2,0]:
        half_idx = len(popped)//2
        queue.append([row[:half_idx] for row in popped[:half_idx]])
        queue.append([row[half_idx:] for row in popped[:half_idx]])
        queue.append([row[:half_idx] for row in popped[half_idx:]])
        queue.append([row[half_idx:] for row in popped[half_idx:]])
        
        # print(queue)  
        
    else:
        if sum_squares == 0:
            white += 1
        else:
            blue += 1
            
print(white)
print(blue)