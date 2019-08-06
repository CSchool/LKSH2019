import random
import sys

random.seed(sys.argv[1])

print(random.randint(1, 10), random.randint(1, 5))
