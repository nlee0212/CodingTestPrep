import sys

def input():
    return sys.stdin.readline().rstrip()

L,C = map(int,input().split(' '))

possibles = input().split(' ')
possibles.sort()
possibles_coord = {k:v+1 for v,k in enumerate(possibles)}

need = set('aeiou')

def dfs(history):
    if len(history) == L:
        # print(history)
        num_need = len(set(history) & need)
        if num_need >= 1 and L-num_need >= 2:
            print(history)
    
    if history:
        if history[-1] == possibles[-1]:
            return
        candidates = possibles[possibles_coord[history[-1]]:]
    else:
        candidates = possibles
        
    for alphabet in candidates:
        # print(alphabet)
        if alphabet not in history:
            dfs(history+alphabet)

dfs('')