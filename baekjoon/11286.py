import sys
import heapq

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

min_heap = []
abs_heap = []

for i in range(N):
    inst = int(input())

    if inst == 0:
        if len(abs_heap) == 0:
            print(0)
        else:
            popped = heapq.heappop(abs_heap)
            if popped != round(popped):
                print(-int(round(popped)))
            else:
                print(popped)
    else:
        if inst < 0:
            heapq.heappush(abs_heap,-inst-0.1)
        else:
            heapq.heappush(abs_heap,inst)

    # print(inst,abs_heap)