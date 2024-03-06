import sys

sys.setrecursionlimit(1000000)

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
bricks = [(0,0,0,0)]
for i in range(N):
    area, height, weight = map(int,input().split(' '))
    
    bricks.append((area,weight,height,i+1))
# print(bricks)

bricks = sorted(bricks)
# print(bricks)
# print(tf)

res = [0 for _ in range(N+1)]

for i in range(1,N+1):
    for j in range(0,i):
        if bricks[j][0] < bricks[i][0] and bricks[j][1] < bricks[i][1]:
            res[i] = max(bricks[i][2] + res[j],res[i]) 


# print(res)

max_value = max(res)
index = N
result = []
while index != 0:
    if max_value == res[index]:
        result.append(bricks[index][-1])
        max_value -= bricks[index][2]
    index -= 1
result.reverse()
print(len(result))
[print(i) for i in result]