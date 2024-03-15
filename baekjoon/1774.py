import sys
from collections import defaultdict
from heapq  import *

def input():
    return sys.stdin.readline().rstrip()

def dist(v1,v2):
    x2 = (v1[0]-v2[0])**2
    y2 = (v1[1]-v2[1])**2
    return (x2+y2)**0.5


N, M = map(int,input().split(' '))

edges = []
vertices = [None for _ in range(N+1)]

parent = {}
rank = {}

def make_set(node):
    parent[node] = node
    rank[node] = 0
    
def union(n1,n2):
    p1 = find(n1)
    p2 = find(n2)
    
    if p1 != p2:
        if rank[p1] > rank[p2]:
            parent[p2] = p1
        elif rank[p2] > rank[p1]:
            parent[p1] = p2
        else:
            if p1 < p2:
                parent[p2] = p1
                rank[p1] += 1
            else:
                parent[p1] = p2
                rank[p2] += 1
                
def find(n):
    if parent[n] != n:
        parent[n] = find(parent[n])
    return parent[n]

for n in range(1,N+1):
    vertices[n] = tuple(map(int,input().split(' ')))
    make_set(n)
    if n > 1:
        for j in range(1,n):
            edges.append(((dist(vertices[j],vertices[n]),j,n)))
    
edges.sort()
added = 0

# mst = list()

for m in range(M):
    n1,n2 = map(int,input().split(' '))
    union(n1,n2)
    
for cost,n1,n2 in edges:
    p1 = find(n1)
    p2 = find(n2)
    
    if p1 != p2:
        added += cost
        union(n1,n2)
        
print("%.2f"%added)