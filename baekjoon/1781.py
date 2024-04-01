import sys
import heapq
from collections import defaultdict

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
hw = []
for n in range(N):
    deadline, reward = map(int,input().split(' '))
    hw.append((deadline,-reward))
    
hw.sort()
queue = []

for deadline,reward in hw:
    if len(queue) < deadline:
        heapq.heappush(queue,-reward)
    elif len(queue) == deadline:
        heapq.heappushpop(queue,-reward)
    # print(queue)

print(sum(queue))