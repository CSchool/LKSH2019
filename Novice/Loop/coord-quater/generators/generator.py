import random
import sys

random.seed(sys.argv[1])

if sys.argv[1] == '0':
    print('{} {}'.format(1, 1))
elif sys.argv[1] == '1':
    print('{} {}'.format(1, -1))
else:
    print('{} {}'.format(random.randint(-1000, 1000), random.randint(-1000, 1000)))
