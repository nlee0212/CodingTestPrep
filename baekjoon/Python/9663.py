import sys


def input():
    return sys.stdin.readline().rstrip()


N = int(input())
row = [0]*N
result = 0

def check(level):
    for i in range(level):
        if abs(row[i]-row[level]) == level-i:
            return False
    return True

def dfs(level):
    global result
        
    for i in range(N):
        if i in row[:level]:
            continue
        row[level] = i
        
        if check(level):
            if level == N-1:
                result += 1
            else:
                dfs(level+1)

    
dfs(0)
print(result)
        