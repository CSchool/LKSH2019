import re

string = input()

list = re.findall(r"[a-zA-Z']+", string)
if len(list) == 0:
    print(0)
else :
    print(len(max(list, key=len)))
