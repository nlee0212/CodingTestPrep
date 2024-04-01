import sys

def input():
    return sys.stdin.readline().rstrip()

R,C = map(int,input().split(' '))
board = []

for r in range(R):
    # board.append(list(input()))
    board.append(input())

queue = set()
queue.add((board[0][0],0,0))
directions = [(-1,0),(1,0),(0,-1),(0,1),]
max_len = 0

while queue:
    history,cur_r,cur_c = queue.pop()
    max_len = max(max_len,len(history))
    
    for dr,dc in directions:
        new_r = cur_r+dr
        new_c = cur_c+dc
        
        if 0 <= new_r < R and 0<=new_c<C and board[new_r][new_c] not in history:
            queue.add((history+board[new_r][new_c],new_r,new_c))
    
print(max_len)