import random
import sys


random.seed(sys.argv[1])

if sys.argv[1] == '0':
    print('100 2')
elif sys.argv[1] == '1':
    print('100 5')
else:
    print('{} {}'.format(random.randint(1, 10000), random.randint(2, 9)))
