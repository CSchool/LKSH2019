import random
import sys


random.seed(sys.argv[1])

def convert_base(num, to_base=10, from_base=10):
    # first convert to decimal number
    if isinstance(num, str):
        n = int(num, from_base)
    else:
        n = int(num)
    # now convert decimal to 'to_base' base
    alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    if n < to_base:
        return alphabet[n]
    else:
        return convert_base(n // to_base, to_base) + alphabet[n % to_base]


if sys.argv[1] == '0':
    print('100\n2')
elif sys.argv[1] == '1':
    print('100\n9')
else:
    scale = random.randint(2, 9)
    number = random.randint(1, 10000)
    print('{}\n{}'.format(convert_base(number, scale), scale))
