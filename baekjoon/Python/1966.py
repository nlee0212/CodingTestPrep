import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

T = int(input())

for i in range(T):
    m_n = input()
    m_ns = m_n.split(' ')
    N = int(m_ns[0])
    M = int(m_ns[1])
    priorities = input().split(' ')
    priority_queue = deque()
    num_queue = deque()

    for num,priority in enumerate(priorities):
        priority_queue.append(int(priority))
        num_queue.append(num)

    turns = 1

    while True:
        if priority_queue[0] != max(priority_queue):
            priority_queue.rotate(-1)
            num_queue.rotate(-1)

        else:
            priority_queue.popleft()
            output = num_queue.popleft()
            
            if output == M:
                print(turns)
                break

            turns += 1



