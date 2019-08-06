
num, degree = map(int, input().split())

result = 1
for i in range(abs(degree)):
    result = result * num

if degree < 0:
    result = 1 / result

print(result)
