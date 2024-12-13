import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

lines = []

draw = []
for n in range(N):
    s,e = map(int,input().split(' '))
    draw.append((s,e))
draw.sort()
cur_start,cur_end = draw[0]

for s,e in draw[1:]:
    if s <= cur_end:
        if e > cur_end:
            cur_end = e
    else:
        lines.append((cur_start,cur_end))
        
        cur_start = s
        cur_end = e
        
if (lines and lines[-1][0] != cur_start) or len(lines) == 0:
    lines.append((cur_start,cur_end))
    
length = 0
for s,e in lines:
    length += e-s
    
print(length)