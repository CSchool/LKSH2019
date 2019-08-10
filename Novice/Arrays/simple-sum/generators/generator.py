import random
import sys

random.seed(sys.argv[1])

if sys.argv[1] == '0':
    print('5\n1 2 3 4 5')
elif sys.argv[1] == '1':
    print('3\n-1 2 -3')
else:
    array_size = random.randint(1, 100)
    array = [str(random.randint(-1000, 1000)) for _ in range(0, array_size)]

    print("{}\n{}".format(array_size, " ".join(array)))
