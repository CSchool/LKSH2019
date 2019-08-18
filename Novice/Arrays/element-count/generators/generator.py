import random
import sys

random.seed(sys.argv[1])

if sys.argv[1] == '0':
    print('5\n4 6 5 4 6')
else:
    array_size = random.randint(1, 100)
    array = [str((random.randint(1, 1000) % 100) + 1) for _ in range(0, array_size)]
    print("{}\n{}".format(array_size, " ".join(array)))

    # if int(sys.argv[1]) < 9:
    #     max_value = random.randint(1, 1000)
    # else:
    #     max_value = random.randint(-600, 0)
    #
    # array = [str(random.randint(-1000, max_value - 1)) for _ in range(0, array_size)]
    # print("{}\n{}".format(array_size, " ".join(array)))

