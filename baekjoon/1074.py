import sys

def input():
    return sys.stdin.readline().rstrip()

N, r, c = map(int,input().split(' '))

# location = []
s_x,s_y = 0,0
res = 0

for i in range(N-1,-1,-1):
    x_loc = int(c >= s_x + 2**i)
    y_loc = int(r >= s_y + 2**i)
    cur_loc = 2*y_loc+x_loc
    # location.append(cur_loc)

    s_x += x_loc*2**i
    s_y += y_loc*2**i

    res += cur_loc*(2**i)**2
    # print('cur_loc',cur_loc,'s_x',s_x,'s_y',s_y,'res',res)

print(res)