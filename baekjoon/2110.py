import sys
sys.setrecursionlimit(10**6)
from itertools import permutations

def input():
    return sys.stdin.readline().rstrip()

N, C = map(int,input().split(' '))

nums = []

for i in range(N):
    nums.append(int(input()))

nums = sorted(nums)

## Binary Search

start, end = 1,nums[-1]-nums[0]
res = 0

while start <= end:
    gap = (start+end)//2
    count = 1
    cur = nums[0]
    for j in range(1,len(nums)):
        if cur+gap <= nums[j]:
            cur = nums[j]
            count += 1
        if count == C:
            break
    if count == C:
        start = gap + 1
        if gap > res: res = gap
    else:
        end = gap-1

print(res)