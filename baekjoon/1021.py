import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()


N, M = map(int,input().split(' '))

q = deque(range(1,N+1))
res = 0

nums = list(map(int,input().split(' ')))
for n in nums:
    right = 0
    
    for candidate in q:
        if candidate == n:
            break
        right += 1

    left = len(q)-right
    
    if left > right:
        q.rotate(-right)
        res += right
    else:
        q.rotate(left)
        res += left
    # print(n, right, q)
    q.popleft()

print(res)