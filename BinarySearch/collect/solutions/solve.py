import sys

fin = sys.stdin
fout = sys.stdout

fin.readline()
a = list(map(int, fin.readline().split()))
fin.readline()
b = list(map(int, fin.readline().split()))
for i in b:
    l = 0
    r = len(a)
    while l + 1 < r:
        mid = (l + r + 1) // 2
        if a[mid] <= i:
            l = mid
        else:
            r = mid
    print('YES' if a[l] == i else 'NO', file=fout)

fin.close()
fout.close()
