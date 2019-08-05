import random
import sys

random.seed(sys.argv[1])

a = random.randint(1, 1000)

print('{} {} {}'.format(a, a, a))
