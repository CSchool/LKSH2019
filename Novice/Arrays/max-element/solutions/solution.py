if __name__ == '__main__':
    size = int(input())
    array = list(map(int, input().split()))

    max_value = max(array)
    max_index = array.index(max_value)

    print('{} {}'.format(max_value, max_index))
