import sys
import heapq

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

min_heap = []

for n in range(N):
    serial = input()
    num_sum = 0
    
    for c in serial:
        if ord('0')<=ord(c)<=ord('9'):
            num_sum += int(c)
    
    
    heapq.heappush(min_heap,(len(serial),num_sum,serial))
    
while min_heap:
    print(heapq.heappop(min_heap)[-1])