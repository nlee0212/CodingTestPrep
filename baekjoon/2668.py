import sys
# from collections import defaultdict

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
edges = dict()

for n in range(1,N+1):
    edges[n] = int(input())
    
selected = [0]*(N+1)
visited = [0]*(N+1)

for n in range(1,N+1):
    if selected[n] or visited[n]:
        continue

    cur = n
    next = edges[n]
    hist = [cur,next]
    visited[n] = 1
    
    while visited[next]==0:
        # print(cur)
        cur = next
        next = edges[cur]
        hist.append(next)
        visited[cur] = 1
        # break
    
    # print(cur,next)
    # print(hist)
    save = [hist.pop()]
    while hist:
        # print(hist)
        # print(save)
        popped = hist.pop()
        if popped != save[0]:
            save.append(popped)
        else:
            for s in save:
                selected[s] = 1
            break
    # print(selected)
    
print(sum(selected))
for s in range(1,N+1):
    if selected[s]:
        print(s)