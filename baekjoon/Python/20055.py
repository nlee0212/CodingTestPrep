import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N, K = map(int,input().split(' '))
stat = list(map(int,input().split(' ')))
robots = [0 for _ in range(2*N)]
robots = deque(robots)
stat = deque(stat)

zero_stat_cnt = 0
level = 0


while zero_stat_cnt < K:
    level += 1

    
    robots.rotate(1)
    stat.rotate(1)
    
    robots[N-1] = 0
    
    for i in range(N-2,-1,-1):
        if robots[i] and robots[i+1] == 0 and stat[i+1] > 0:
            # print(i,'->',i+1)
            robots[i] = 0
            robots[i+1] = 1
            stat[i+1] -= 1
            if stat[i+1] == 0:
                zero_stat_cnt += 1  
    robots[N-1] = 0

    
    if stat[0] >  0 and robots[0] == 0:
        robots[0] = 1
        stat[0] -= 1
        if stat[0] == 0:
            zero_stat_cnt += 1

    
print(level)