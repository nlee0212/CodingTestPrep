import sys

def input():
    return sys.stdin.readline().rstrip()

N, M = map(int,input().split(' '))

need_row = set(range(N))
need_col = set(range(M))

rows= []
for i in range(N):
    row = input()
    for j,r in enumerate(row):
        if r == 'X':
            need_row = need_row - {i}
            need_col = need_col - {j}

    rows.append(row)

print(max(len(need_row),len(need_col)))