import sys

def input():
    return sys.stdin.readline().rstrip()

T = int(input())

for t in range(T):
    n = int(input())
    picked_list = list(map(int,input().split(' ')))
    
    pick = dict()
    for s,p in zip(range(1,n+1),picked_list):
        pick[s] = p
    
    team = [0]*(n+1)
    visited = [0]*(n+1)
    
    for s in range(1,n+1):
        if team[s] or visited[s]:
            continue
        # cur_visited = [0]*(n+1)
        # cur_visited[s] = 1
        cur = s
        pre_team = [s]
        while True:
            if visited[cur]:
                break
            # print(cur)
            # cur_visited[cur] = 1
            visited[cur] = 1
            next = pick[cur]
            if next == cur:
                team[cur] = 1
                break
            else:
                if visited[next]:
                    flag = False
                    for teammate in pre_team:
                        if teammate == next:
                            flag = True
                        if flag:
                            team[teammate] = 1
                    break
                else:
                    pre_team.append(next)
            cur = next
            
        # print(team)
        
    print(n-sum(team))