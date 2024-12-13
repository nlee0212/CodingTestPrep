import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

cards = deque(range(1,N+1))

while len(cards) > 1:
    cards.popleft()
    cards.rotate(-1)

print(cards[0])
