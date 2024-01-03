import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
q = deque()

for i in range(N):
    cmd = input()
    cmds = cmd.split(' ')

    if cmds[0] == 'push_front':
        q.appendleft(int(cmds[1]))
    elif cmds[0] == 'push_back':
        q.append(int(cmds[1]))
    elif cmd == 'pop_front':
        if len(q) == 0:
            print(-1)
        else:
            print(q.popleft())
    elif cmd == 'pop_back':
        if len(q) == 0:
            print(-1)
        else:
            print(q.pop())
    elif cmd == 'size':
        print(len(q))
    elif cmd == 'empty':
        print(int(len(q)==0))
    elif cmd == 'front':
        if len(q) == 0:
            print(-1)
        else:
            print(q[0])
    elif cmd == 'back':
        if len(q) == 0:
            print(-1)
        else:
            print(q[-1])
