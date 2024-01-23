import sys
import heapq

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
lectures = []
# times = set()

for i in range(N):
    num,start,end = map(int,input().split(' '))
    # lectures.append((start,end))
    heapq.heappush(lectures,(start,end))
    # times.add(start)
    # times.add(end)

# lectures = sorted(lectures,key=lambda x:-x[0])
# print(lectures)
# print(times)
cnt = 0
late_end = []
# cur_time = min(times)

# for t in times:
while len(lectures):
    
    popped = heapq.heappop(lectures)
    if len(late_end) == 0:
        heapq.heappush(late_end,popped[1])
        cnt += 1
        
        
    else:
        popped_end_time = heapq.heappop(late_end)
        if popped_end_time > popped[0]:
            cnt += 1
            heapq.heappush(late_end,popped[1])
            heapq.heappush(late_end,popped_end_time)
        else:
            heapq.heappush(late_end,popped[1])


    # print(popped,lectures,late_end)
        
print(cnt)