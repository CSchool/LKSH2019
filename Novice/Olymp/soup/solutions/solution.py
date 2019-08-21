if __name__ == '__main__':
    n, m, ind_size = map(int, input().split())
    indegrients = list(map(int, input().split()))
    soup = list()

    result = set()

    for i in range(0, n):
        soup.append(list(map(int, input().split())))

    for i in range(0, n):
        for j in range(0, m):
            if soup[i][j] in indegrients:
                result.add(soup[i][j])

    print('YES' if len(result) == len(indegrients) else 'NO')
