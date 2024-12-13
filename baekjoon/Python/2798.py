import sys
from itertools import combinations

def input():
    return sys.stdin.readline().rstrip()

N,M = map(int,input().split(' '))

cards = list(map(int,input().split(' ')))

closest = -1

for card_sets in combinations(cards,3):
    summed = sum(card_sets)    
    if summed > M:
        continue
    if M - summed < M - closest:
        closest = summed
print(closest)