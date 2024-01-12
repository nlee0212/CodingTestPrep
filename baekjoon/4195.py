import sys


def input():
    return sys.stdin.readline().rstrip()

def find_parent(parent_dict,num):
    if num == parent_dict[num]:
        return num
    else:
        parent = find_parent(parent_dict,parent_dict[num])
        parent_dict[num] = parent
        return parent_dict[num]

def union(parent_dict,child_num,num1,num2):
    p1 = find_parent(parent_dict,num1)
    p2 = find_parent(parent_dict,num2)

    if p1 != p2:
        parent_dict[p2] = p1
        child_num[p1] += child_num[p2]

N = int(input())

for n in range(N):
    F = int(input())
    
    parent = {}
    child_num = {}
    
    for f in range(F):
        n1,n2 = input().split(' ')

        if n1 not in parent:
            parent[n1] = n1
            child_num[n1] = 1
        if n2 not in parent:
            parent[n2] = n2
            child_num[n2] = 1

        union(parent,child_num,n1,n2)
        print(child_num[find_parent(parent,n1)])