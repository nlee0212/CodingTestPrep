import sys
import heapq

def input():
    return sys.stdin.readline().rstrip()

heap = []

N = int(input())
table_dict = {}

# table = []
for i in range(N):
    row = list(map(int,input().split(' ')))
    for r in row:
        heapq.heappush(heap,r)
    if len(heap) > N:
        for j in range(N):
            heapq.heappop(heap)
    # print(heap)
print(heapq.heappop(heap))