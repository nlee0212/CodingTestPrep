import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

ppl = list(map(int,input().split(' ')))

B,C = map(int,input().split(' '))

cnt = 0
for p in ppl:
    cnt += 1
    p -= B
    
    if p > 0:
        cnt += p//C + int(p%C > 0)
        
print(cnt)