import sys
import heapq

def input():
    return sys.stdin.readline().rstrip()

N, K = map(int,input().split(' '))
sack = list()
value_per_weight = [[0 for _ in range(K+1)] for i in range(N+1)]


for i in range(N):
    w,v = map(int,input().split(' '))

    for j in range(K+1):
        if j < w:
            value_per_weight[i+1][j] = value_per_weight[i][j]
        else:
            value_per_weight[i+1][j] = max(value_per_weight[i][j],value_per_weight[i][j-w]+v)

print(value_per_weight[-1][-1])