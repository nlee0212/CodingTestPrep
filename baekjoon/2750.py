import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

nums = []
for i in range(N):
    nums.append(int(input()))

for n in sorted(nums):
    print(n)