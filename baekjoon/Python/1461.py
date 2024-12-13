import sys
import heapq

def input():
    return sys.stdin.readline().rstrip()


N, M = map(int,input().split(' '))
books = list(map(int,input().split(' ')))
largest = max(max(books),-min(books))

if N == 1:
    print(abs(books[0]))
    exit()

 
positive = []
negative = []

for b in books:
    if b >= 0:
        heapq.heappush(positive,-b)
    else:
        heapq.heappush(negative,b)
    
dist = 0    
    
while positive:
    dist += -heapq.heappop(positive)
    for i in range(M-1):
        if positive:
            heapq.heappop(positive)
        
while negative:
    dist += -heapq.heappop(negative)
    for i in range(M-1):
        if negative:
            heapq.heappop(negative)

print(dist*2 - largest)