import math

if __name__ == '__main__':
    a, b, c = map(int, input().split())

    if a + b > c and a + c > b and b + c > a:
        if a == b == c:
            print('EQUILATERAL TRIANGLE')
        elif a == b or a == c or b == c:
            print('ISOSCELES TRIANGLE')
        else:
            print('PLAIN TRIANGLE')
    else:
        print('NOT TRIANGLE')

