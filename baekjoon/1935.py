import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

start = ord('A')
end = ord('Z')
cmd = input()
hash_dict = dict()


idx = start
for i in range(N):
    hash_dict[chr(idx)] = int(input())
    idx += 1

q = deque()
for c in cmd:
    if ord(c) >= start and ord(c) <= end:
        q.append(hash_dict[c])
    else:
        b = q.pop()
        a = q.pop()

        if c == '+':
            q.append(a+b)
        elif c == '-':
            q.append(a-b)
        elif c == '*':
            q.append(a*b)
        elif c == '/':
            q.append(a/b)

print("%.2f" % (q.pop()))


