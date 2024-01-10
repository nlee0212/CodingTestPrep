# Useful Functions
that I forget to use pretty often..

## Queue
```Python
from collections import deque

queue = deque()
...
rotated_queue = queue.rotate(-1) # left
queue.popleft()
queue.appendleft()
```
- Useful for queue construction

## Map
```Python
list_of_ints = list(map(int,input().split(' ')))
```
- Useful for fast transition of numbers splitted with ' ' into list of ints

## Set
```Python
S = set()
S.add('element')
```
- Just like append, you don't need to assign it to S again! (Not `S = S.add(e)`)

## Heap
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
heap = heapq.heapify(heap)
```
- initialize heap as just `list()`
- `heappush(heap,element)`: construct min-heap
- `heappop(heap)`: pop min element
- If you want to make a max-heap, you can simply put '-' when pushing & popping.
- If you already have a list, use `heapify`.

