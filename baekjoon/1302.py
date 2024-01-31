import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())

books = {}

for i in range(N):
    book = input()
    books[book] = books.get(book,0)+1

books_sorted = sorted(books.items(),key=lambda x:(-x[1],x[0]))
print(books_sorted[0][0])