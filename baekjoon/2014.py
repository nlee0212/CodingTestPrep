import sys
from itertools import combinations_with_replacement
import heapq

def input():
    return sys.stdin.readline().rstrip()

K, N = map(int,input().split(' '))
nums = list(map(int,input().split(' ')))
heap = nums.copy()
num_set = set()
# num_set = set(nums)

heapq.heapify(heap)
max_num = nums[-1]
# print(heap)
for i in range(N):
    popped = heapq.heappop(heap)
    # popped_list.add(popped)

    for n in nums:
        new_num = popped*n
        if new_num not in num_set:
            if len(heap) > N-i-1 and new_num > max_num:
                continue
            heapq.heappush(heap,new_num)
            num_set.add(new_num)
            max_num = max(max_num,new_num)

    # print(popped,heap)

print(popped)