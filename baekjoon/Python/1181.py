import sys
import heapq

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

words = []
for n in range(N):
    word = input()
    if (len(word),word) in words:
        continue
    heapq.heappush(words,(len(word),word))
    
while words:
    print(heapq.heappop(words)[-1])