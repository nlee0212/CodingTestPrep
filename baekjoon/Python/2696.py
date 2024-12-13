import sys
import heapq

def input():
    return sys.stdin.readline().rstrip()

T = int(input())

for t in range(T):
    M = int(input())
    print(M//2+1)
    if M <= 10:
        nums = list(map(int,input().split(' ')))
    else:
        nums = []
        for m in range(M//10+1):
            nums += list(map(int,input().split(' ')))

    left = [] # max_heap
    right = [] # min_heap
    left_cnt = 0
    right_cnt = 0

    cur_mid = nums[0]
    print(cur_mid,end=' ')
    
    for i in range(1,M):
        if i % 20 == 0:
            print()
            
        cur = nums[i]
        if cur < cur_mid:
            heapq.heappush(left,-cur)
            left_cnt += 1
        else:
            heapq.heappush(right,cur)
            right_cnt += 1

        if i % 2 == 0:
            if left_cnt > right_cnt:
                heapq.heappush(right,cur_mid)
                cur_mid = -heapq.heappop(left)
                left_cnt -= 1
                right_cnt += 1
            elif left_cnt < right_cnt:
                heapq.heappush(left,-cur_mid)
                cur_mid = heapq.heappop(right)
                left_cnt += 1
                right_cnt -= 1

            # print(left,right)
            print(cur_mid,end=' ')

    print()