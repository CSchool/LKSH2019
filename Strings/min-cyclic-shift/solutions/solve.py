import sys


def code(c):
    return ord(c) - 96


def hash(s):
    h = 0
    a = [0]
    for sym in s:
        h = (h * BASE + code(sym)) % MOD
        a.append(h)
    return a


s = input()
t = input() * 2
m = len(s)
n = len(t)
MOD = 10 ** 9 + 7
BASE = 29
C = (BASE ** m) % MOD
h1 = hash(s)
h2 = hash(t)

for i in range(m):
    if h1[-1] == (h2[i + m] - h2[i] * C) % MOD:
        print(i)
        sys.exit(0)
print(-1)
