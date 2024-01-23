import sys


def input():
    return sys.stdin.readline().rstrip()

s = input()

idx_dict = dict()

for i,c in enumerate(s):
    if c not in idx_dict:
        idx_dict[c] = i

for i in range(ord('a'),ord('z')+1):
    print(idx_dict.get(chr(i),-1),end=' ')