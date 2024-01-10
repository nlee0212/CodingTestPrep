import sys
import heapq

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
heap = []

for i in range(N):
    num = int(input())

    if num == 0:
        if heap:
            print(-heapq.heappop(heap))
        else:
            print(0)
    else:
        heapq.heappush(heap,-num)