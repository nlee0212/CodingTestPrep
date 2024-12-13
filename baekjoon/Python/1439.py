import sys

def input():
    return sys.stdin.readline().rstrip()

S = input()

change = 0
cur = S[0]

for s in S:
    if cur != s:
        change += 1
        cur = s
        
print(change//2 + change%2)    