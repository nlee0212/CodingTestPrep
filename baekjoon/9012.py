import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

for i in range(N):
    cnt = 0
    break_flag = 0
    cmd = input()

    for c in cmd:
        if c == '(':
            cnt += 1
        else:
            if cnt == 0:
                break_flag = 1
                break
            cnt -= 1
    if break_flag or cnt != 0:
        print('NO')
    else:
        print('YES')
