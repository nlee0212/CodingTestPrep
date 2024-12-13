import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

fibonacci_list = [-1]*46

fibonacci_list[0] = 0
fibonacci_list[1] = 1

for i in range(2,N+1):
    fibonacci_list[i] = fibonacci_list[i-1] + fibonacci_list[i-2]

print(fibonacci_list[N])