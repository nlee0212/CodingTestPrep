import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

nums = list(map(int,input().split(' ')))

x = int(input())

trash = []

nums.sort()

start = 0
end = N-1
count = 0

while start < end:
    if nums[start] + nums[end] > x:
        end -= 1
    elif nums[start] + nums[end] < x:
        start += 1
    else:
        count += 1
        end -= 1
        
print(count)