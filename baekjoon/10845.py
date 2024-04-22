import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

queue = deque([])

def push(x):
    queue.append(x)
    
def pop():
    if queue:
        popped = queue.popleft()
    else:
        popped = -1
        
    print(popped)

def size():
    print(len(queue))
    
def empty():
    if queue:
        print(0)
    else:
        print(1)
        
def front():
    if queue:
        print(queue[0])
    else:
        print(-1)
        
def back():
    if queue:
        print(queue[-1])
        
    else:
        print(-1)
        
for n in range(N):
    cmd = input()
    
    if cmd == 'pop':
        pop()
        
    elif cmd == 'size':
        size()
        
    elif cmd == 'empty':
        empty()
        
    elif cmd ==  'front':
        front()
        
    elif cmd == 'back':
        back()
        
    else:
        _,x = cmd.split(' ')
        push(x)