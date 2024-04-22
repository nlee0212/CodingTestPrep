import sys
import math

def input():
    return sys.stdin.readline().rstrip()


n,k = map(int,input().split(' '))

res = 1
for i in range(k):
    res *= (n-i)

res = res // math.factorial(k)

print(res)