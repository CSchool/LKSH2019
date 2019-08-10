import collections

if __name__ == '__main__':
    size = int(input())
    array = list(map(int, input().split()))
    result = collections.OrderedDict(sorted(collections.Counter(array).items(), key=lambda t: t[0]))

    for number, count in result.items():
        print("{} {}".format(number, count))
