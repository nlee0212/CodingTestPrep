import sys
from collections import Counter

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
cards = list(map(int,input().split(' ')))
cards_stat = Counter(cards)

M = int(input())
nums = list(map(int,input().split(' ')))

res = []
for n in nums:
    res.append(str(cards_stat[n]))
    
print(' '.join(res))