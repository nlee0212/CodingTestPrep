import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
numbers = list(map(int,input().split(' ')))
res_list = [""]*N
stack = list()
cnt = 0

for i,n in enumerate(numbers):

    if cnt > 0:
        while cnt:
            if stack[-1][0] < n:
                res_list[stack.pop()[1]] = str(n)
                cnt -= 1
            else:
                break
    stack.append((n,i))
    cnt += 1

while cnt:
    res_list[stack.pop()[1]] = str(-1)
    cnt -= 1

print(' '.join(res_list))