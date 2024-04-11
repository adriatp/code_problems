import pandas as pd
from urllib.request import urlopen
import json

a = json.loads(urlopen('https://codember.dev/colors.txt').read())

values = set(a)

list_1 = [s1 + s2 for s1, s2 in zip(a[::2], a[1::2])]
list_2 = [s1 + s2 for s1, s2 in zip(a[1::2], a[2::2])]


def max_consecutive(llista):
    max_len = -1
    act_len = 0
    color = ''
    fp = 0
    lp = 0
    for i in range(len(llista)-1):
        if (llista[i] == llista[i+1]):
            act_len += 1
        else:
            act_len = 0
        if act_len > max_len:
            fp = i-act_len
            lp = i
            max_len = act_len
            color = llista[i]
    return max_len, color

print("{}".format(max_consecutive(list_1)))
print("{}".format(max_consecutive(list_2)))