import sys
sys.setrecursionlimit(10**6)

def input():
    return sys.stdin.readline().rstrip()


N = int(input())

color_map = []
for n in range(N):
    color_map.append(list(input()))

normal_visited = [[0 for _ in range(N)] for _ in range(N)]    
rg_visited = [[0 for _ in range(N)] for _ in range(N)]    

normal_cnt = 0
rg_cnt = 0    
directions = [(-1,0),(1,0),(0,1),(0,-1)]

def normal_dfs(cur_i,cur_j,color):
    for di,dj in directions:
        newi = cur_i+di
        newj = cur_j+dj
        
        if 0<=newi<N and 0<=newj<N and not normal_visited[newi][newj] and color_map[newi][newj] == color:
            normal_visited[newi][newj] = 1
            normal_dfs(newi,newj,color)
            
def rg_dfs(cur_i,cur_j,color):
    for di,dj in directions:
        newi = cur_i+di
        newj = cur_j+dj
        
        if 0<=newi<N and 0<=newj<N and not rg_visited[newi][newj] and color_map[newi][newj] in color:
            rg_visited[newi][newj] = 1
            rg_dfs(newi,newj,color)
        
        
rg = 'RG'
    
for i in range(N):
    for j in range(N):
        if not normal_visited[i][j]:
            normal_cnt += 1
            normal_visited[i][j] = 1
            normal_dfs(i,j,color_map[i][j])
        if not rg_visited[i][j]:
            rg_cnt += 1
            rg_visited[i][j] = 1
            if color_map[i][j] in rg:
                rg_dfs(i,j,rg)
            else:
                rg_dfs(i,j,'B')
                
print(normal_cnt,rg_cnt)