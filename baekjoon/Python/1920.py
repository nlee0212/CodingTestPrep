import sys

def input():
    return sys.stdin.readline().rstrip()
    
N = int(input())
A = set(map(int,input().split(' ')))
M = int(input())

for num in list(map(int,input().split(' '))):
    if num in A:
        print(1)
    else:
        print(0)