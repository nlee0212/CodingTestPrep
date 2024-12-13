import sys

def input():
    return sys.stdin.readline().rstrip()

N, M = map(int,input().split(' '))

board = []

min_change = N*M

w = list('WB')*4
b = list('BW')*4

for n in range(N):
    board.append(list(input()))
    
def check(start_i,start_j):
    # print(start_i,start_j)
    change_cnt =  0
    
    wb = [w,b]*4
    bb = [b,w]*4
    
    wb_cnt =  0
    bb_cnt =  0
        
    for i in range(8):
        for j  in range(8):
            if board[start_i+i][start_j+j] != wb[i][j]:
                wb_cnt += 1
            if board[start_i+i][start_j+j] != bb[i][j]:
                bb_cnt += 1
                
    return min(wb_cnt,bb_cnt)
    
for i in range(N-7):
    for j in range(M-7):
        min_change = min(min_change,check(i,j))
        
print(min_change)