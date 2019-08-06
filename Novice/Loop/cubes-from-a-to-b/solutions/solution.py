a, b = map(int, input().split())


if a > b:
    a, b = b, a

for a in range(a, b + 1):
    print(a * a * a)