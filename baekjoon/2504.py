import sys
def input():
    return sys.stdin.readline().rstrip()

s = input()

cur = -1 # -1: first, 0: close, 1: open
stack = list()
res_str = ''
break_flag = 0

for c in s:
    if c == '(':
        stack.append(c)
        if cur == 0:
            res_str += "+"
        res_str += "2*("
        cur = 1
    elif c == '[':
        stack.append(c)
        if cur == 0:
            res_str += "+"
        res_str += "3*("
        cur = 1
    
    elif c == ')':
        if len(stack) == 0:
            break_flag = 1
            break

        popped = stack.pop()
        if popped != '(':
            break_flag = 1
            break

        if cur == 0: #close then close
            res_str += ")"
    
        else:
            res_str += "1)"

        cur = 0

    elif c == ']':
        if len(stack) == 0:
            break_flag = 1
            break

        popped  = stack.pop()
        if popped != '[':
            break_flag = 1
            break

        if cur == 0:
            res_str += ")"

        else:
            res_str += "1)"
    
        cur = 0

# print(res_str)

if break_flag:
    print(0)
else:
    try:
        exec(f"print({res_str})")
    except:
        print(0)