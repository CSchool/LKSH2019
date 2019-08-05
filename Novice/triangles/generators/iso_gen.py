import random
import sys

random.seed(sys.argv[1])

a = b = c = 0

while not (a + b > c and a + c > b and b + c > a and a != b and a != c):
    a = random.randint(1, 1000)
    b = random.randint(1, 1000)
    c = b

sides = [a, b, c]
random.shuffle(sides)

print('{} {} {}'.format(sides[0], sides[1], sides[2]))
