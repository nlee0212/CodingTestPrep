import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

board = []
max_num = 0

for n in range(N):
    row = list(map(int,input().split(' ')))
    board.append(row)
    max_num = max(max_num,max(row))
    
direction = [(-1,0),(1,0),(0,-1),(0,1)] # up, down, left, right


def push(board,d):
    di,dj = direction[d]
    
    change_cnt = 0
    
    if d%2 == 0:
        for i in range(N):
            for j in range(N):
                newi = i+di
                newj = j+dj
                while board[newi-di][newj-dj] != 0 and 0<=newi<N and 0<=newj<N and board[newi][newj] == 0:
                    board[newi][newj] = board[newi-di][newj-dj]
                    board[newi-di][newj-dj] = 0
                    change_cnt += 1
                    newi = newi+di
                    newj = newj+dj
                    
    else:
        for i in range(N-1,-1,-1):
            for j in range(N-1,-1,-1):
                newi = i+di
                newj = j+dj
                while board[newi-di][newj-dj] != 0 and 0<=newi<N and 0<=newj<N and board[newi][newj] == 0:
                    board[newi][newj] = board[newi-di][newj-dj]
                    board[newi-di][newj-dj] = 0
                    change_cnt += 1
                    newi = newi+di
                    newj = newj+dj
    
    return board, change_cnt

def add(board,d):
    di,dj = direction[d]
    change_cnt = 0
    global max_num
    
    if d%2 == 0:
        for i in range(N):
            for j in range(N):
                newi = i+di
                newj = j+dj
                if board[i][j] != 0 and 0<=newi<N and 0<=newj<N and board[newi][newj] == board[i][j]:
                    board[newi][newj] *= 2
                    max_num = max(max_num,board[newi][newj])
                    board[i][j] = 0
                    change_cnt += 1
                    
    else:
        for i in range(N-1,-1,-1):
            for j in range(N-1,-1,-1):
                newi = i+di
                newj = j+dj
                if board[i][j] != 0 and 0<=newi<N and 0<=newj<N and board[newi][newj] == board[i][j]:
                    board[newi][newj] *= 2
                    max_num = max(max_num,board[newi][newj])
                    board[i][j] = 0
                    change_cnt += 1
                    
    return board, change_cnt

queue = deque([(board,0,-1)])


while queue:
    cur_board,before_step,before_d = queue.popleft()
    
    for d in range(4):
        
        # print(direction[d])    
        # print('BEFORE')
        # for row in cur_board:
        #     print(row)
        total_change_cnt = 0
        new_board, change_cnt = push([row[:] for row in cur_board],d)
        total_change_cnt += change_cnt
        
        new_board, add_change_cnt = add(new_board,d)
        total_change_cnt += add_change_cnt
        
        if add_change_cnt > 0:
            new_board, change_cnt = push(new_board,d)
            total_change_cnt += change_cnt
        
        # print('AFTER')
        # for row in new_board:
        #     print(row)
        
        if total_change_cnt > 0 and before_step < 4:
            queue.append((new_board,before_step+1,d))
            
print(max_num)
        
        