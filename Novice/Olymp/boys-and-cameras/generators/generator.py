import random
import sys

random.seed(sys.argv[1])

if sys.argv[1] == '0':
    print('8\n3 1 -4 1 5 9 -2 -6')
elif sys.argv[1] == '1':
    print('1\n5')
else:
    num = random.randint(2, 100)
    array = [str(random.randint(-20, 20)) for x in range(0, num)]
    print("{}\n{}".format(num, " ".join(array)))
