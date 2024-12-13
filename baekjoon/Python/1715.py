import sys
import heapq

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

heap = []
for i in range(N):
    heapq.heappush(heap,int(input()))

res = 0

while len(heap) > 1:
    popped_1 = heapq.heappop(heap)
    popped_2 = heapq.heappop(heap)
    summed = popped_1 + popped_2
    res += summed
    heapq.heappush(heap,summed)
    
print(res)