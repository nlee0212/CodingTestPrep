import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N, K = map(int,input().split(' '))

vase = list(map(int,input().split(' ')))
direction = [(-1,0),(1,0),(0,-1),(0,1)]

cnt = 0
while True:
    max_cnt = max(vase)
    min_cnt = min(vase)
    if max_cnt - min_cnt <= K:
        break
    
    cnt += 1
    # print(vase)
    
    for i in range(N):
        if vase[i] == min_cnt:
            vase[i] += 1
    # print(vase)
    # 
    # 1,1,2,2,3,3,4,4,... 
    # 1x1,2x1,2x2,3x2,3x3,4x3,...
    
    cur_step = 1
    lift_vase = deque([deque(vase)])
    
    while True:
        if len(lift_vase[-1])-cur_step >= cur_step:
            bulk = deque([])
            for j in range(cur_step):
                row = deque([])
                for i in range(cur_step):
                    row.appendleft(lift_vase[i].popleft())
                bulk.appendleft(row)
            
            # print(bulk)
            for cs in range(cur_step-1):
                lift_vase.popleft()
            lift_vase.extendleft(bulk)
            
            # for row in lift_vase:
            #     print(row)
            # print()
            
        else:
            break
        
        if len(lift_vase[-1])-cur_step >= cur_step+1:
            bulk = deque([])
            for j in range(cur_step):
                row = deque([])
                for i in range(cur_step+1):
                    row.appendleft(lift_vase[i].popleft())
                bulk.appendleft(row)
            # print(lift_vase)
            for cs in range(cur_step):
                lift_vase.popleft()
            lift_vase.extendleft(bulk)
            
            # for row in lift_vase:
            #     print(row)
            # print()
            
        else:
            break
        
        cur_step += 1
        
    change = []
    for i in range(len(lift_vase)):
        row = []
        for j in range(len(lift_vase[i])):
            change_num = 0
            for di,dj in direction:
                newi,newj = i+di,j+dj
                if 0<=newi<len(lift_vase) and 0<=newj<len(lift_vase[newi]):
                    if lift_vase[newi][newj] > lift_vase[i][j]:
                        change_num += (lift_vase[newi][newj]-lift_vase[i][j])//5
                    else:
                        change_num -= (lift_vase[i][j]-lift_vase[newi][newj])//5
            row.append(change_num)
        change.append(row)
    for i in range(len(lift_vase)):
        for j in range(len(lift_vase[i])):
            lift_vase[i][j] += change[i][j]
            
    # for row in lift_vase:
    #     print(row)
    # print()
    
    vase = deque()
    for j in range(cur_step):
        row = deque()
        for i in range(len(lift_vase)):
            row.appendleft(lift_vase[i].popleft())
        vase.extend(row)
    vase.extend(lift_vase[-1])
    
    # print(vase)
    lift_vase = deque([deque(vase)])
    
    for rep in range(2):
        bulk = deque()
        for i in range(len(lift_vase)):
            size = len(lift_vase[i])//2
            row = deque()
            for j in range(size):
                row.appendleft(lift_vase[i].popleft())
            bulk.append(row)
        lift_vase.extendleft(bulk)
        
        # for row in lift_vase:
        #     print(row)
        # print()
        
    change = []
    for i in range(len(lift_vase)):
        row = []
        for j in range(len(lift_vase[i])):
            change_num = 0
            for di,dj in direction:
                newi,newj = i+di,j+dj
                if 0<=newi<len(lift_vase) and 0<=newj<len(lift_vase[newi]):
                    if lift_vase[newi][newj] > lift_vase[i][j]:
                        change_num += (lift_vase[newi][newj]-lift_vase[i][j])//5
                    else:
                        change_num -= (lift_vase[i][j]-lift_vase[newi][newj])//5
            row.append(change_num)
        change.append(row)
    for i in range(len(lift_vase)):
        for j in range(len(lift_vase[i])):
            lift_vase[i][j] += change[i][j]
            
    # for row in lift_vase:
    #     print(row)
    # print()
        
    vase = deque()
    # print(size)
    for j in range(len(lift_vase[-1])):
        row = deque()
        for i in range(len(lift_vase)):
            row.appendleft(lift_vase[i].popleft())
        vase.extend(row)
    vase.extend(lift_vase[-1])
    
    # print(vase)
    
    
    # break   
print(cnt)