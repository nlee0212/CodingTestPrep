import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N_K = input()
N_K = N_K.split(' ')
N = int(N_K[0])
K = int(N_K[1])

q = deque(range(1,N+1))
outputs = list()
while len(q) > 0:
    q.rotate(-(K-1))
    outputs.append(str(q.popleft()))

print('<'+', '.join(outputs)+'>')
