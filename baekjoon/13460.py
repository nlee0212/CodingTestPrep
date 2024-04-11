import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N,M = map(int,input().split(' '))

board = []
for n in range(N):
    board.append(list(input()))
    for i,item in enumerate(board[n]):
        if item == 'R':
            cur_r = [n,i]
        if item == 'B':
            cur_b = [n,i]
    
d = [(-1,0),(1,0),(0,-1),(0,1)]

queue = deque()

queue.append((0,-1,cur_r,cur_b,board))

while queue:
    before_step, before_dir, cur_r,cur_b,cur_board = queue.popleft()
    if before_step == 10:
        print(-1)
        exit()
    # print('#',before_step+1)
    
    # print('RED:',cur_r)
    # print('BLUE:',cur_b)
    # for row in cur_board:
    #     print(row)
    
    for i,(di,dj) in enumerate(d):
        if i//2 == before_dir//2:
            continue
        
        # print(di,dj)
        new_r = cur_r.copy()
        new_b = cur_b.copy()
        r_in = False
        b_in = False
        
        change_cnt = 0
        new_board = [row[:] for row in cur_board]
        
        while new_board[new_r[0]+di][new_r[1]+dj] in '.O':
            change_cnt += 1
            new_board[new_r[0]][new_r[1]] = '.'
            new_r[0] += di
            new_r[1] += dj
            if new_board[new_r[0]][new_r[1]] == 'O':
                r_in=True
                break
            else:
                new_board[new_r[0]][new_r[1]] = 'R'
            
        while new_board[new_b[0]+di][new_b[1]+dj] in '.O':
            change_cnt += 1
            new_board[new_b[0]][new_b[1]] = '.'
            new_b[0] += di
            new_b[1] += dj
            if new_board[new_b[0]][new_b[1]] == 'O':
                b_in=True
                break
            else:
                new_board[new_b[0]][new_b[1]] = 'B'
        if b_in:
            continue
        
        while new_board[new_r[0]+di][new_r[1]+dj] in '.O':
            change_cnt += 1
            new_board[new_r[0]][new_r[1]] = '.'
            new_r[0] += di
            new_r[1] += dj
            if new_board[new_r[0]][new_r[1]] == 'O':
                r_in=True
                break
            else:
                new_board[new_r[0]][new_r[1]] = 'R'
            
        while new_board[new_b[0]+di][new_b[1]+dj] in '.O':
            change_cnt += 1
            new_board[new_b[0]][new_b[1]] = '.'
            new_b[0] += di
            new_b[1] += dj
            if new_board[new_b[0]][new_b[1]] == 'O':
                b_in=True
                break
            else:
                new_board[new_b[0]][new_b[1]] = 'B'
        if b_in:
            continue
        
        # for row in new_board:
        #     print(row)
            
        if r_in and not b_in:
            print(before_step+1)
            exit()
        # print(change_cnt)
        if not r_in and not b_in and change_cnt > 0:
            queue.append((before_step+1,i,new_r,new_b,new_board))
print(-1)