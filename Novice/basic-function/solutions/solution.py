import math

x = int(input())

if x == 0:
    print(0)
elif x > 0:
    print(2 * x - 10)
else:
    print((int)(2 * math.fabs(x) - 1))
