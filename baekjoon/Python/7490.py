import sys

def input():
    return sys.stdin.readline().rstrip()


T = int(input())

for t in range(T):
    N = int(input())

    start = ["1"]
    for i in range(2,N+1):
        cur = []
        for s in start:
            cur.append(s+f" {i}")
            cur.append(s+f"+{i}")
            cur.append(s+f"-{i}")
        start = cur

    for s in start:
        exec(f"res = {s.replace(' ','')}")
        # print(res)
        if res == 0:
            print(s)
    print()