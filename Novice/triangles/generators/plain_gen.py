import random
import sys

random.seed(sys.argv[1])

a = b = c = 0
digit_set = set()

while not (len(digit_set) == 3 and (a + b > c and a + c > b and b + c > a)):
    digit_set.clear()
    a = random.randint(1, 1000)
    b = random.randint(1, 1000)
    c = random.randint(1, 1000)
    digit_set.add(a)
    digit_set.add(b)
    digit_set.add(c)

print('{} {} {}'.format(a, b, c))
