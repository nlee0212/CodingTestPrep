import sys

def input():
    return sys.stdin.readline().rstrip()

doc = input()
word = input()
len_word = len(word)

i = 0
cnt = 0

while i < len(doc):
    if doc[i:i+len_word] == word:
        cnt += 1
        i += len_word
    else:
        i += 1

print(cnt)