import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N,K = map(int,input().split(' '))
res = []
q = deque(range(1,N+1))

for i in range(N):
    q.rotate(-(K-1))
    res.append(str(q.popleft()))

print(f"<{', '.join(res)}>")