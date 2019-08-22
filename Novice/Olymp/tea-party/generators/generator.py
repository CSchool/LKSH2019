import random
import sys

random.seed(sys.argv[1])

if sys.argv[1] == '0':
    print('5\n2 4 6 8 10')
else:
    test = int(sys.argv[1])
    left = 2 if 0 < test < 10 else 100
    right = 100 if 0 < test < 10 else 200
    num = random.randint(left, right)
    array = [str(random.randint(0, 100)) for x in range(0, num)]

    print("{}\n{}".format(num, " ".join(array)))
