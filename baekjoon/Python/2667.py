import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

house_map = []
for n in range(N):
    house_map.append(list(map(int,list(input()))))
# print(house_map)
    
visited = [[0 for n in range(N)] for n in range(N)]

# print(visited)

village_cnt = 0
directions = [(-1,0),(1,0),(0,1),(0,-1)]
cur_village_house_cnt = 0
village_house_cnt_list = []

def dfs(cur_i,cur_j):
    global cur_village_house_cnt
     
    for di,dj in directions:
        newi = cur_i + di
        newj = cur_j + dj
        if 0<=newi<N and 0<=newj<N and not visited[newi][newj] and house_map[newi][newj]:
            # print(newi,newj)
            visited[newi][newj] = 1
            cur_village_house_cnt += 1 
            dfs(newi,newj)
            
for i in range(N):
    for j in range(N):
        if not visited[i][j] and house_map[i][j]:
            village_cnt += 1
            cur_village_house_cnt = 1
            visited[i][j] = 1
            dfs(i,j)
            # print(visited)
            # print()
            village_house_cnt_list.append(cur_village_house_cnt)
            
village_house_cnt_list.sort()
print(village_cnt)
for c in village_house_cnt_list:
    print(c) 