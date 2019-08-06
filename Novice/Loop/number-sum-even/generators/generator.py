import random
import sys

random.seed(sys.argv[1])

print(random.randint(1, 100000))
