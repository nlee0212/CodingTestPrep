import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

node_dict = dict()

for i in range(N):
    cur,left,right = input().split(' ')
    node_dict[cur] = (left,right)

preorder,midorder,postorder = '','',''
# print(node_dict)
visited = {k:0 for k in node_dict.keys()}

def dfs(cur,preorder,midorder,postorder):
    if cur == '.' or visited[cur]:
        return preorder,midorder,postorder
        
    visited[cur] = 1
    # print(cur)
    preorder += cur
    preorder,midorder,postorder = dfs(node_dict[cur][0],preorder,midorder,postorder)
    midorder += cur
    preorder,midorder,postorder = dfs(node_dict[cur][1],preorder,midorder,postorder)
    postorder += cur

    return preorder,midorder,postorder

preorder,midorder,postorder = dfs('A',preorder,midorder,postorder)

print(preorder,midorder,postorder,sep='\n')