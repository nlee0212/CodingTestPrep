import sys

def input():
    return sys.stdin.readline().rstrip()

str_num = sorted(list(input()),reverse=True)
print(''.join(str_num))