if __name__ == '__main__':
    size = int(input())
    array = list(map(int, input().split()))

    sum = 0

    for i in range(0, len(array)):
        sum += array[i]

    print(sum)
