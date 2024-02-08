import sys
from collections import deque,defaultdict

def input():
    return sys.stdin.readline().rstrip()

node_dict = dict()

N = int(input())
all = set()
children = set()

for i in range(N):
    cur,left,right = map(int,input().split(' '))
    node_dict[cur] = (left,right)
    children.add(left)
    children.add(right)

visited = {k:0 for k in node_dict.keys()}
level_dict = defaultdict(list)
head = set(node_dict.keys()) - children
head = head.pop()

def dfs(cur,idx,level):
    if cur == -1 or visited[cur]:
        return idx
    idx = dfs(node_dict[cur][0],idx,level+1)
    visited[cur] = 1
    # print(cur)
    level_dict[level].append(idx)
    idx += 1
    idx = dfs(node_dict[cur][1],idx,level+1)

    return idx
# print(head)
idx = dfs(head,1,1)
# print(level_dict)

max_l = 0
max_wid  = 0
for l in range(1,len(level_dict)+1):
    nodes = level_dict[l]
    width=nodes[-1]-nodes[0]+1
    if width > max_wid:
        max_wid = width
        max_l = l

print(max_l,max_wid)