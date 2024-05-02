import sys

def input():
    return sys.stdin.readline().rstrip()

N,M = map(int,input().split(' '))
pw_dict = dict()

for n in range(N):
    web,pw = input().split(' ')
    pw_dict[web] = pw
    
for m in range(M):
    print(pw_dict[input()])