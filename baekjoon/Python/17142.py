import sys
# from itertools import combinations
from collections import deque
from copy import deepcopy

def combinations(arr, n):
    if n == 0:
        return [[]]
    result = []
    for i in range(len(arr)):
        front = arr[i]
        for back in combinations(arr[i + 1:], n - 1):
            result.append([front] + back)
    return result

def input():
    return sys.stdin.readline().rstrip()


N,M = map(int,input().split(' '))
lab = []
viruses = []
blank_cnt = 0

for n in range(N):
    row = list(map(int,input().split(' ')))
    lab.append(row)
    for i in range(N):
        if row[i] == 2:
            viruses.append((n,i))
            row[i] = '*'
        elif row[i] == 0:
            row[i] = -1
            blank_cnt += 1
        elif row[i] == 1:
            row[i] = '-'

if blank_cnt == 0:
    print(0)
    exit()

possibles = []
search = [(-1,0),(1,0),(0,-1),(0,1)]
min_time = float('inf')

for selected in combinations(viruses,M):
    # print(selected)
    new_lab = [row[:] for row in lab]
    queue = deque()
    
    for vr,vc in selected:
        new_lab[vr][vc] = 0
        queue.append((vr,vc))
    cur_blank_cnt = blank_cnt
    
    while queue:
        cur_r,cur_c = queue.popleft()

        for dr,dc in search:
            new_r = cur_r+dr
            new_c = cur_c+dc
            
            if 0<=new_r<N and 0<=new_c<N:
                if new_lab[new_r][new_c] == -1 or new_lab[new_r][new_c] == '*':
                    if new_lab[new_r][new_c] == -1:
                        cur_blank_cnt -= 1
                    new_lab[new_r][new_c] = new_lab[cur_r][cur_c] + 1
                    
                    
                    if cur_blank_cnt == 0:
                        break
                    else:
                        queue.append((new_r,new_c))
        if cur_blank_cnt == 0:
            break
    
    taken = 0
    for i in range(N):
        for j in range(N):
            if lab[i][j] == -1:
                taken = max(taken,new_lab[i][j])
    if cur_blank_cnt == 0:
        min_time = min(taken,min_time)
        
if min_time < float('inf'):
    print(min_time)
else:
    print(-1)