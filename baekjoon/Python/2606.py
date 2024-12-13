import sys
from collections import defaultdict

def input():
    return sys.stdin.readline().rstrip()

parent = dict()
child_num = dict()

def find_parent(e):
    
    if parent[e] == e:
        return e
    
    before_parent = parent[e]
    new_parent = find_parent(before_parent)
    parent[e] = new_parent
    
    return new_parent

def union(e1,e2):
    p1 = find_parent(e1)
    p2 = find_parent(e2)
    
    if p1 != p2:
        if p1 < p2:
            parent[p2] = p1
            child_num[p1] += child_num[p2]
        else:
            parent[p1] = p2
            child_num[p2] += child_num[p1]
            
    # print(parent)
    # print(child_num)
    
N = int(input())
E = int(input())

for i in range(E):
    e1, e2 = map(int,input().split(' '))
    
    if e1 not in parent:
        parent[e1] = e1
        child_num[e1] = 1
    if e2 not in parent:
        parent[e2] = e2
        child_num[e2] = 1
        
    union(e1,e2)


if 1 not in parent:
    print(0)
    exit(
        
    )  
p = find_parent(1)

print(child_num[p]-1)