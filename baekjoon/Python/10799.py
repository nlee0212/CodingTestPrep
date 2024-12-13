import sys

def input():
    return sys.stdin.readline().rstrip()

given = input()
counts = 0
opens = list()

for i,c in enumerate(given):
    if c == '(':
        opens.append(i)
    if c == ')':
        popped = opens.pop()
        if popped == i-1:
            counts += len(opens)
        else:
            counts += 1
print(counts)
