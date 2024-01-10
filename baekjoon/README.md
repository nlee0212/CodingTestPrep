# Useful Functions
that I forget to use pretty often..

```Python
from collections import deque

queue = deque()
...
rotated_queue = queue.rotate(-1) # left
queue.popleft()
queue.appendleft()
```
- Useful for queue construction

```Python
list_of_ints = list(map(int,input().split(' ')))
```
- Useful for fast transition of numbers splitted with ' ' into list of ints

```Python
S = set()
S.add('element')
```
- Just like append, you don't need to assign it to S again! (Not `S = S.add(e)`)
