import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

def push(q,x):
    q.appendleft(x)
    return q

def pop(q):
    if len(q) == 0:
        print(-1)
    else:
        print(q.pop())

    return q

def size(q):
    print(len(q))

def empty(q):
    print(int(len(q) == 0))

def front(q):
    if len(q) == 0:
        print(-1)
    else:
        print(q[-1])

def back(q):
    if len(q) == 0:
        print(-1)
    else:
        print(q[0])

N = int(input())

q = deque()
for i in range(N):

    cmd = input()
    cmds = cmd.split(' ')

    if cmds[0] == 'push':
        q = push(q,int(cmds[1]))
    elif cmd == 'pop':
        q = pop(q)
    elif cmd == 'size':
        size(q)
    elif cmd == 'empty':
        empty(q)
    elif cmd == 'front':
        front(q)
    elif cmd == 'back':
        back(q)


    
