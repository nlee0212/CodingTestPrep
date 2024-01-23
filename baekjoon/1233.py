import sys
from collections import Counter

def input():
    return sys.stdin.readline().rstrip()

s1,s2,s3 = map(int,input().split(' '))
freq_dict = dict()

for i in range(1,s1+1):
    for j in range(1,s2+1):
        for k in range(1,s3+1):
            freq_dict[i+j+k] = freq_dict.get(i+j+k,0) + 1

freq_dict_sorted = sorted(freq_dict.items(),key=lambda x:(x[1],-x[0]))
# print(freq_dict_sorted)
print(freq_dict_sorted[-1][0])