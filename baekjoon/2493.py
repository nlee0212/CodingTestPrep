import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

tops = input().split(' ')
tops = [int(t) for t in tops]

res = []

for i,top in enumerate(tops):
    if i == 0:
        res.append(0)
    else:
        if tops[i-1] > top:
            res.append(i)
        else:
            cur = i-1
            while True:
                high = res[cur]
                if high == 0:
                    res.append(0)
                    break
                if tops[high-1] < top:
                    cur = high-1
                else:
                    res.append(high)
                    break
                    
res = [str(r) for r in res]
print(' '.join(res))
