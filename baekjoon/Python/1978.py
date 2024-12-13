import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

nums = list(map(int,input().split(' ')))

cnt = 0
for n in nums:
    flag = False
    
    if n == 1:
        continue
    
    for i in range(2,n):
        if n%i == 0:
            flag = True
            break
        
    if not flag:
        cnt += 1
        
print(cnt)