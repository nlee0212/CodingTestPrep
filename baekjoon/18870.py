import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

nums = list(map(int,input().split(' ')))

sorted_nums = sorted(list(set(nums)))
n2id = {}
for i,n in enumerate(sorted_nums):
    n2id[n] = str(i)
    
packed = [n2id[n] for n in nums]
print(' '.join(packed))