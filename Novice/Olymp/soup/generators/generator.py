import random
import sys

random.seed(sys.argv[1])

def random_not_from_list(forbidden_list):
    value = forbidden_list[0]
    while value in forbidden_list:
        value = random.randint(1, 1000)
    return value

def random_unique_list(size):
    existed_values = set()
    values = []
    for i in range(0, size):
        value = random.randint(1, 1000)
        while value in existed_values:
            value = random.randint(1, 1000)

        values.append(value)
        existed_values.add(value)

    return values

if sys.argv[1] == '0':
    print('2 2 2\n1 2\n3 2\n1 4')
else:
    n = random.randint(1, 100)
    m = random.randint(1, 100)
    ind_size = random.randint(1, 30)
    indegrients = random_unique_list(ind_size)

    indegrients_str = list(map(str, indegrients))

    test = int(sys.argv[1])
    array = []

    for i in range(0, n):
        row = [random_not_from_list(indegrients) for x in range(0, m)]
        array.append(row)

    if 0 < test < 5:
        ind_limits = 1
    elif 5 <= test < 10:
        ind_limits = 0.5
    else:
        ind_limits = 0

    if ind_limits > 0:
        ind_limit = round(len(indegrients) * ind_limits)
        saved_indigrients = [indegrients.pop(indegrients.index(random.choice(indegrients))) for i in range(0, ind_limit)]
        pairs = list()
        for i in range(0, n):
            for j in range(0, m):
                pairs.append((i, j))

        while len(saved_indigrients) > 0:
            element = saved_indigrients.pop(saved_indigrients.index(random.choice(saved_indigrients)))
            place = pairs.pop(pairs.index(random.choice(pairs)))
            array[place[0]][place[1]] = element

    # array to str
    array_result = ""
    for i in range(0, n):
        row_str = " ".join(map(str, array[i]))
        array_result += "{}\n".format(row_str)

    print('{} {} {}\n{}\n{}'.format(n, m, ind_size, ' '.join(indegrients_str), array_result.strip('\n')))
