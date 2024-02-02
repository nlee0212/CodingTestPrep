import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

nums = []
max_h = -1
max_idx = -1
left = 0
right = 0

for i in range(N):
    cur = int(input())
    nums.append(cur)

    if cur > max_h:
        left += 1
        max_h = cur
        max_idx = i
        
# print('max_idx',max_idx)
# print(nums[-1:max_idx:-1])

max_h = -1
for cur in nums[::-1]:
    # print(cur,max_h)
    if cur > max_h:
        right += 1
        max_h = cur

print(left)
print(right)