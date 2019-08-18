from functools import reduce
import sys

s = input()
BASE = 29
MOD = 10 ** 9 + 9

prefixHashes = [0]
postfixHashes = [0]
pows = [1]
for i in range(len(s)):
    prefixHashes.append((prefixHashes[i] * BASE + ord(s[i]) - 96) % MOD)
    postfixHashes.append((postfixHashes[i] * BASE + ord(s[-1 - i]) - 96) % MOD)
    pows.append(pows[i] * BASE % MOD)

for _ in range(int(input())):
    start, finish = map(int, input().split())
    BL = pows[finish - start + 1]
    a = (prefixHashes[finish] - prefixHashes[start - 1] * BL) % MOD
    b = (postfixHashes[-start] - postfixHashes[-1 - finish] * BL) % MOD
    if a == b:
        print("+", end='')
    else:
        print("-", end='')
