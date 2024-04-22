import sys

def input():
    return sys.stdin.readline().rstrip()

T = int(input())

res = [(1,0),(0,1),(1,1)]
len_res = len(res)

for t in range(T):
    n = int(input())
    
    if len_res <= n:
        need = n-len_res+1
        # print(need)
        for i  in range(need):
            n_1 = res[-1]
            n_2 = res[-2]
            new =  (n_1[0]+n_2[0],n_1[1]+n_2[1])
            res.append(new)
             
        # print(len(res))
    print(*res[n])
        
    len_res = len(res)