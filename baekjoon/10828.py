import sys

def input():
    return sys.stdin.readline().rstrip()

def pop(stack):
    if len(stack) == 0:
        print(-1)
    else:
        print(stack.pop())
    return stack

def size(stack):
    print(len(stack))

def empty(stack):
    print(int(len(stack) == 0))

def top(stack):
    if len(stack) == 0:
        print(-1)
    else:
        print(stack[-1])


N = int(input())
stack = list()

for i in range(N):
    com = input()
    coms = com.split(' ')
    
    if coms[0] == 'push':
        stack.append(int(coms[1]))

    elif coms[0] == 'top':
        top(stack)

    elif coms[0] == 'size':
        size(stack)

    elif coms[0] == 'pop':
        pop(stack)

    elif coms[0] == 'empty':
        empty(stack)
