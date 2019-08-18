if __name__ == '__main__':
    size = int(input())
    array = list(map(int, input().split()))

    print(" ".join(map(lambda x: str(x), sorted(array))))
