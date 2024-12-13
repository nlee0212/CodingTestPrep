import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

for i in range(N):
    before_str = deque()
    after_str = deque()
    before_cnt = 0
    after_cnt = 0
    
    written = input()

    for c in written:
        if c == '<':
            if before_cnt > 0:
                p = before_str.pop()
                after_str.appendleft(p)
                before_cnt -= 1
                after_cnt += 1
        elif c == '>':
            if after_cnt > 0:
                p = after_str.popleft()
                before_str.append(p)
                before_cnt += 1
                after_cnt -= 1
        elif c == '-':
            if before_cnt > 0:
                before_str.pop()
                before_cnt -= 1
        else:
            before_str.append(c)
            before_cnt += 1
            
            
    print(''.join(before_str)+''.join(after_str))