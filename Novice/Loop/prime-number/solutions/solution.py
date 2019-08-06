number = int(input())

isPrime = True

if number > 1:
    for i in range (2, number // 2):
        if number % i == 0:
            isPrime = False
else:
    isPrime = False

print("Prime" if isPrime else "Not prime")