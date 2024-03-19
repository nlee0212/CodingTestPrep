import sys
# import numpy as np 
# from heapq import *

def input():
    return sys.stdin.readline().rstrip()

# def int_minus(n):
#     return -int(n)

N = int(input())
limits = list(map(int,input().split(' ')))

M = int(input())
boxes = list(map(int,input().split(' ')))

if max(limits) <max(boxes):
    print(-1)
    exit()

sec = 0

limits.sort(reverse=True)
boxes.sort(reverse=True)

# heapify(boxes)
# if boxes[0] > limits[0]:
#     print(-1)
#     exit()
    
sent = [False] * M
positions = [0] * N
sent_box_cnt = 0

while sent_box_cnt != M:
    sec += 1
    for i in range(N):
        for j in range(positions[i],M):
            if not sent[j] and boxes[j] <= limits[i]:
                sent[j] = True
                sent_box_cnt += 1
                if sent_box_cnt == M:
                    print(sec)
                    exit()
                break
            positions[i] = j+1
            
print(sec)
