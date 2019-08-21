from itertools import islice, count
from math import sqrt


def is_prime(n):
    return n > 1 and all(n % i for i in islice(count(2), int(sqrt(n) - 1)))


if __name__ == '__main__':
    # индексы массива - с 1 (!)
    array_size = int(input())
    array = list(map(int, input().split()))
    sum = 0

    counter = 0

    for i in range(1, len(array) + 1):
        if is_prime(i):
            counter += 1

    print(counter)
