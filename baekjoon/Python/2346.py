import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

bs = input().split(' ')
bs = [int(b) for b in bs]
q = deque(bs)
num_q = deque(range(1,N+1))

outputs = list()

while len(q) > 0:
    output = q.popleft()
    num = num_q.popleft()
    outputs.append(str(num))

    if output > 0:
        q.rotate(-1*(output-1))
        num_q.rotate(-1*(output-1))
    else:
        q.rotate(-1*output)
        num_q.rotate(-1*output)

print(' '.join(outputs))
