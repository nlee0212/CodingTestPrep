import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
cnt = 0
num = 666
res_num = num

while cnt < N:
    if '666' in str(num):
        cnt += 1
        res_num = num
    num += 1
        
print(res_num)