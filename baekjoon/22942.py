import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

xrs = []

for i in range(N):
    xr = input().split(' ')
    x,r = int(xr[0]),int(xr[1])

    if i == 0:
        xrs.append((x,r))
        continue
    
    for px,pr in xrs:
        dist = abs(px-x)
        if dist >= abs(pr-r) and dist <= pr+r:
            print('NO')
            exit()
print('YES')