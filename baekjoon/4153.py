import sys

def input():
    return sys.stdin.readline().rstrip()

while True:
    a,b,c =  map(int,input().split(' '))
    
    if a==0 and b==0 and c ==0:
        break
    
    max_num = max([a,b,c])
    
    others = [n for n in [a,b,c] if n != max_num]
    
    if max_num**2 == others[0]**2+others[1]**2:
        print('right')
    else:
        print('wrong')