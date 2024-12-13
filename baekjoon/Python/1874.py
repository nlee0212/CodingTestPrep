import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

q = deque()
outputs = list()
max_flag = 0
cand = deque(range(1,N+1))
order = list()

for i in range(N):
    num = int(input())
    q.append(num)

    
    if len(order)>0 and order[-1] == num:
        order.pop()
        outputs.append('-')
        continue

    flag = 0
    while len(cand) > 0:
        order.append(cand.popleft())
        outputs.append('+')

        if order[-1] == num:
            order.pop()
            outputs.append('-')
            flag = 1
            break
    if not flag:
        outputs = 'NO'
        break

if outputs == 'NO':
    print(outputs)
else:
    print('\n'.join(outputs))
