import random
import sys

random.seed(sys.argv[1])
print(random.randint(10, 1000))
