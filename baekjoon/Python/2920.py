
import sys

def input():
    return sys.stdin.readline().rstrip()

notes = list(map(int, input().split(' ')))

prev = 0
for i,note in enumerate(notes):
    if i == 0:
        continue
    if i == 1:
        prev = note-notes[i-1]
    else:
        if prev != note-notes[i-1]:
            print('mixed')
            prev = -100
            break

if prev == 1:
    print('ascending')
elif prev == -1:
    print('descending')