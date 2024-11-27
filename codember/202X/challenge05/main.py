import pandas as pd
from urllib.request import urlopen
import json

a = json.loads(urlopen('https://codember.dev/mecenas.json').read())

max_2_pot = 0

i = 0
while (2**(i+1) <= len(a)):
    i += 1
max_2_pot = 2**(i)
idx = (len(a) - max_2_pot) * 2