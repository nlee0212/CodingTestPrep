import sys

def input():
    return sys.stdin.readline().rstrip()

i,j = 0,0

str_1 = input()
str_2 = input()
dp = [[0] * (len(str_2) + 1) for _ in range(len(str_1) + 1)]

str_1 = ' '+str_1
str_2 = ' '+str_2

for i in range(1,len(str_1)):
    found = None
    dp[i] = dp[i-1].copy()
    for j in range(1,len(str_2)):
        
        if str_1[i] == str_2[j]:
            dp[i][j] = dp[i-1][j-1]+1
        else:
            dp[i][j] = max(dp[i][j-1], dp[i-1][j])

print(max(dp[-1]))