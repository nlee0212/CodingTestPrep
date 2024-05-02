import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()


N,M = map(int,input().split())

nums = list(map(int,input().split()))

nums.sort()

res = []

def dfs(count,path,idx):
    if count == 0:
        res.append(path)
        return
    
    for i,n in enumerate(nums[idx:]):
        dfs(count-1,path+[n],i+idx)
        
dfs(M,[],0)

# print(res)
for r in res:
    print(*r)