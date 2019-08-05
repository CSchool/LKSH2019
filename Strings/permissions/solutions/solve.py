MOD = 106033
hashtable = [[] for i in range(MOD)]
n = int(input())
for i in range(n):
    a = input().strip().split()
    h = hash(a[0]) % MOD
    hashtable[h] += [a]
m = int(input())
for t in range(m):
    request = input().strip().split()
    h = hash(request[1]) % MOD
    c = request[0][0].upper()
    if c == 'E':
        c = 'X'
    for el in hashtable[h]:
        if request[1] == el[0] and c in el:
            print('OK')
            break
    else:
        print('Access denied')
