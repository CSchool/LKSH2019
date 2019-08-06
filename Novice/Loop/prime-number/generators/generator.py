import random
import sys

random.seed(sys.argv[1])

range = int(sys.argv[2])

print(random.randint(1, range))