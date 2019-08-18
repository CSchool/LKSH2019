import random
import sys

random.seed(sys.argv[1])

if sys.argv[1] == '0':
    print('5\n6 1 5 4 9')
else:
    array_size = random.randint(100, 10000)
    array = [str(random.randint(0, 10000)) for _ in range(0, array_size)]
    print("{}\n{}".format(array_size, " ".join(array)))
