import sys

def input():
    return sys.stdin.readline().rstrip()

a,b = map(int,input().split(' '))

min_num = min(a,b)
max_factor = 1

for i in range(2,min_num+1):
    if a%i == 0 and b%i==0:
        max_factor = i
        
print(max_factor)

print(max_factor * (a//max_factor) * (b//max_factor))