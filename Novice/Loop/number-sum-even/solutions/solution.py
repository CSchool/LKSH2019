import math

if __name__ == '__main__':
    number = int(input())
    sum = 0

    while number != 0:
        last_digit = number % 10
        if last_digit % 2 == 0:
            sum += last_digit
        number = number // 10

    print(sum)
