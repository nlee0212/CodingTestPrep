import sys
import hashlib

def input():
    return sys.stdin.readline().rstrip()

S = input()
print(hashlib.sha256(S.encode()).hexdigest())
