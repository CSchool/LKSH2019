import calendar

if __name__ == '__main__':
    year = int(input())
    is_leap = calendar.isleap(year)
    print(366 if is_leap else 365)
