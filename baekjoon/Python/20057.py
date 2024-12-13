import sys
from collections import deque
from math import trunc

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

board = []
for n in range(N):
    board.append(list(map(int,input().split(' '))))
    
outside = 0
scatter_left = {
    (-1,0):0.07,
    (1,0):0.07,
    (-2,0):0.02,
    (2,0):0.02,
    (-1,-1):0.1,
    (1,-1):0.1,
    (-1,1):0.01,
    (1,1):0.01,
    (0,-2):0.05,
    (0,-1):0
}

scatter_right = {(k[0],-k[1]):v for k,v in scatter_left.items()}
scatter_up = {(k[1],k[0]):v for k,v in scatter_left.items()}
scatter_down = {(-k[0],k[1]):v for k,v in scatter_up.items()}

# print(scatter_left)
# print(scatter_right)
# print(scatter_down)
# print(scatter_up)

new_r = N//2
new_c = N//2
direction = deque([(0,-1),(1,0),(0,1),(-1,0)])
direction_scatter = {
    (0,-1):scatter_left,
    (0,1):scatter_right,
    (1,0):scatter_down,
    (-1,0):scatter_up
}

for i in range(2*N-1):
    step = i//2+1
    cur_dir = direction[0]
    scatter = direction_scatter[cur_dir]
    # print(step)
    for j in range(step):
        new_r,new_c = new_r+cur_dir[0],new_c+cur_dir[1]
        # print('cur coord',new_r,new_c)
        new_sand = board[new_r][new_c]
        left_sand = new_sand
        
        for (dr,dc),ratio in scatter.items():
            nnr = new_r+dr
            nnc = new_c+dc
            # print('new_cord',nnr,nnc)
            move_sand = trunc(new_sand*ratio)
            left_sand -= move_sand
            # print('ratio',ratio,'move',move_sand,'left',left_sand)
            if 0<=nnr<N and 0<=nnc<N:
                if ratio == 0:
                    board[nnr][nnc] += left_sand
                else:
                    board[nnr][nnc] += move_sand
                
            else:
                if ratio == 0:
                    outside += left_sand
                else:
                    outside += move_sand
        
            # for r in range(N):
            #     print(board[r])
            # print(outside)
        board[new_r][new_c] = 0
        if new_r == 0 and new_c == 0:
            break
        
    direction.rotate(-1)
    
# for r in range(N):
#     print(board[r])
print(outside)