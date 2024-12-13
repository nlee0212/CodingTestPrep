import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

seq = list(map(int,input().split(' ')))

if N == 1:
    print(1)
    exit()
    
dp_list = [1 for i in range(N)]

for i in range(N-2,-1,-1):
    max_len = 1
    for j in range(i+1,N):
        # print(i,j)
        if seq[j] > seq[i]:
            if max_len < dp_list[j]+1:
                max_len = dp_list[j]+1
    dp_list[i] = max_len
                
# print(max_len)
print(max(dp_list))