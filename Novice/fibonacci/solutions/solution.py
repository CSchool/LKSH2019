def fib():
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b


if __name__ == '__main__':
    input_value = int(input())
    result = ""

    for index, fibonacci_number in zip(range(input_value + 2), fib()):
        if index > 1:
            result += "{} ".format(fibonacci_number)

    print(result.strip())
