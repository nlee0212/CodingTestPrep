import sys

def input():
    return sys.stdin.readline().rstrip()

def sing(num):
    left = num
    sec = 0
    # print(left)
    if num == 1:
        return 1
    for i in range(1,num+1):
        if left < i:
            sec += sing(left)
            break
        else:
            # print(i,left)
            sec += 1
            left -= i
    return sec

sec = sing(int(input()))
print(sec)