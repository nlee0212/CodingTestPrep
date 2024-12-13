import sys

def input():
    return sys.stdin.readline().rstrip()

while True:
    s = input()
    if s == '0':
        break
    
    len_s = len(s)
    
    if len_s == 1:
        print('yes')
        continue
    
    if len_s%2 == 0:
        before = s[:len_s//2]
        after = s[len_s//2:]
        
    else:
        before = s[:len_s//2]
        after = s[len_s//2+1:]
     
    if before == after[::-1]:
        print('yes')
    else:
        print('no')