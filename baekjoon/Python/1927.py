import sys
import heapq

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

heap = []

for i in range(N):
    num = int(input())

    if num == 0:
        if not heap:
            print(0)
        else:
            print(heapq.heappop(heap))

    else:
        heapq.heappush(heap,num)