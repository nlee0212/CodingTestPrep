import sys

def input():
    return sys.stdin.readline().rstrip()

N, K = map(int,input().split(' '))
nums = sorted(list(map(int,input().split(' '))))
print(nums[K-1])