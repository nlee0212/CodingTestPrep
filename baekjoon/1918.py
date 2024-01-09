import sys

def input():
    return sys.stdin.readline().rstrip()

mid = input()

stack = list()
output = ""

priority = {
    '+':1,'-':1,'*':2,'/':2,'(':0,')':0
}

for c in mid:
    if c not in '+-*/()':
        output += c

    else:
        if c == ')':
            while len(stack) > 0:
                cur = stack.pop()
                if cur == '(':
                    break
                else:
                    output += cur
        elif c == '(':
            stack.append(c)
        else:
            while len(stack) > 0:
                if priority[stack[-1]] >= priority[c]:
                    output += stack.pop()
                else:
                    break
            stack.append(c)
    # print(stack)
while len(stack) > 0:
    output += stack.pop()

print(output)