import sys
import itertools

def input():
    return sys.stdin.readline().rstrip()

s = input()

res_list = []
idx = list()
pairs = list()
word2list = list(s)

for i,c in enumerate(s):
    if c == '(':
        idx.append(i)
    elif c == ')':
        before = idx.pop()
        pairs.append((before,i))
        tmp = word2list.copy()
        tmp[before] = ''
        tmp[i] = ''
        res_list.append(''.join(tmp))


if len(pairs) == 1:
    res_list = sorted(set(res_list))
    print('\n'.join(res_list))
    exit()

res_list.append(s.replace('(','').replace(')',''))

if len(pairs) == 2:
    res_list = sorted(set(res_list))
    print('\n'.join(res_list))
    exit()


for i in range(1,len(pairs)-1):
    pick = i+1
    for ps in itertools.combinations(pairs,pick):
        tmp = word2list.copy()
        for p in ps:
            tmp[p[0]] = ''
            tmp[p[1]] = ''
        res_list.append(''.join(tmp))
    
res_list = sorted(set(res_list))
print('\n'.join(res_list))
