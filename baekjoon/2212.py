import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
K = int(input())
sensors = list(set(map(int,input().split(' '))))
sensors.sort()

if N == 1 or N == K:
    print(0)
    exit()

dists = []
for i in range(len(sensors)-1):
    dists.append(sensors[i+1]-sensors[i])
dists.sort()

for i in range(K-1):
    dists.pop()
print(sum(dists))