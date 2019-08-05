import random
import sys

random.seed(sys.argv[1])

a = b = c = 1

while a + b > c and a + c > b and b + c > a:
    a = random.randint(1, 1000)
    b = random.randint(1, 1000)
    c = random.randint(1, 1000)

print('{} {} {}'.format(a, b, c))
