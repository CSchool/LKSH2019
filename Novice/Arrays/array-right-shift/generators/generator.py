import random
import sys

random.seed(sys.argv[1])

if sys.argv[1] == '0':
    array_number = 5
else:
    array_number = random.randint(1, 100)

print(array_number)
array = random.sample(range(100), array_number)
print(*array)
print(random.randint(1, array_number))