if __name__ == '__main__':
    x, y = map(int, input().split())

    if x == 0 or y == 0:
        print('NONE')
    else:
        if x > 0:
            if y > 0:
                print('FIRST')
            else:
                print('FOURTH')
        else:
            if y > 0:
                print('SECOND')
            else:
                print('THIRD')
