# Useful Functions
that I forget to use pretty often..

## Data Structure
### Queue
```Python
from collections import deque

queue = deque()
...
queue.rotate(-1) # left
queue.popleft()
queue.appendleft()
l = [1,2,3,4]
queue.extend(l) # queue += l
queue.extendleft(l) # queue = l + queue
queue.insert(idx,element) # insert element at idx
queue.index(element) # find index of element
```
- Useful for queue construction

### Map
```Python
list_of_ints = list(map(int,input().split(' ')))
```
- Useful for fast transition of numbers splitted with ' ' into list of ints

### Set
```Python
S = set()
S.add('element')
S.remove('element')
```
- Just like append, you don't need to assign it to S again! (Not `S = S.add(e)`)

### Heap
```Python
import heapq

N = int(input())
heap = []
for i in range(N):
    a = int(input())
    if a == 0:
        if heap:
            print(-heapq.heappop(heap))
        else:
            print(0)
    heapq.heappush(heap, -a)

heap = [1,2,3,4]
heapq.heapify(heap)
```
- initialize heap as just `list()`
- `heappush(heap,element)`: construct min-heap
- `heappop(heap)`: pop min element
- If you want to make a max-heap, you can simply put '-' when pushing & popping.
- If you already have a list, use `heapify`.

### Hash
```Python
import hashlib
input_data = input()
encoded_data = input_data.encode() # 문자열의 바이트 객체
result = hashlib.sha256(encoded_data).hexdigest() 
print(result) # 해시 결과
```
- `sha256` provides the hash value of a given encoded string.

## Algorithm
### Union Find
```Python
def find_parent(parent_dict,num):
    # path compression
    if num != parent_dict[num]:
        parent = find_parent(parent_dict,parent_dict[num]) 
        parent_dict[num] = parent
    return parent_dict[num]

def union(parent_dict,child_num,num1,num2):
    p1 = find_parent(parent_dict,num1)
    p2 = find_parent(parent_dict,num2)

    ## union-by-rank + smaller nodes be the parents if equal condition
    if rank[p1] > rank[p2]:
        parent[p2] = p1
        child_num[p1] += child_num[p2]
    elif rank[p1] < rank[p2]:
        parrent[p1] = p2
        child_num[p2] += child_num[p1]
    else:
        if p1 < p2:
            parent[p2] = p1
            rank[p1] += 1
            child_num[p1] += child_num[p2]
        else:
            parent[p1] = p2
            rank[p2] += 1
            child_num[p2] += child_num[p1]

N = int(input())

for n in range(N):
    F = int(input())
    
    parent = {}
    child_num = {}
    rank = {}
    
    for f in range(F):
        n1,n2 = input().split(' ')

        if n1 not in parent:
            parent[n1] = n1
            child_num[n1] = 1
            rank[n1] = 0
            
        if n2 not in parent:
            parent[n2] = n2
            child_num[n2] = 1
            rank[n2] = 0

        union(parent,child_num,n1,n2)
        print(child_num[find_parent(parent,n1)])
```
- `find()`: find the oldest ancestor & update the parents of all nodes to him
- `union()`: set the parent of the second node as the parent of the first node if they weren't originally from the same union
- make sure to `find()` once more when calculating the final child count!

### Topology Sort
```Python
from collections import defaultdict
import heapq

graph = defaultdict(list)
degree = dict()

for start,end in nodes:
    heapq.heappush(graph[start],end)
    degree[end] = degree.get(end,0) + 1

level_0s = list(set(POSSIBLE_NUMS)-set(degree))
heapq.heapify(level_0s)
result = []

while level_0s:
    popped = heapq.heappop(level_0s)
    result.append(popped)
    for node in graph[popped]:
        degree[node] -= 1
        if degree[node] == 0:
            heapq.heappush(level_0s,node)

for r in result: print(r,end=' ')
```
1. Construct a graph with directed edges
2. Save the level of each node in real-time
3. Start with nodes with level 0, think of this as a sorted queue
4. Pop the queue of level 0 nodes, which will return the smallest node
5. Eliminate the node from the graph by decreasing the degrees of its children.
6. If any of its children become a level 0 node, add them to the sorted queue.
7. Repeat until the queue is empty.
8. If the queue gets empty before all nodes are visited, then it means that there is a cycle within the graph (ERROR when thinking of a topology sort)

## Other Useful Python Functions
### Execution
```Python
s = "1+3-5"
exec(f"res = {s}")
print(res) # -1

res = eval(s)
print(res) # -1
```
- `exec()`: execute the given code, including saving into a variable. No return.
- `eval()`: execute the given code & return the result
