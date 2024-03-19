import sys

def input():
    return sys.stdin.readline().rstrip()

cost = int(input())

rem = 1000-cost

money_list = [500,100,50,10,5,1]
total_cnt = 0
cur = 0

while rem:
    if rem < money_list[cur]:
        cur += 1
        continue
    
    cnt = rem // money_list[cur]
    total_cnt +=  cnt
    rem -= cnt * money_list[cur]
    
print(total_cnt)