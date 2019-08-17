n = int(input())

var = "xyz"
mn = [0, 0, 0]
mx = [101, 101, 101]
cond = []

for i in range(n):
    s = input().split()
    try:
        x = int(s[2])
    except ValueError:
        x = None

    v = var.index(s[0])

    if x is not None:
        if s[1] == ">":
            mn[v] = max(mn[v], x + 1)
        else:
            mx[v] = min(mx[v], x)
    else:
        cond.append((v, var.index(s[2])))

ans = 0

for x in range(mn[0], mx[0]):
    for y in range(mn[1], mx[1]):
        for z in range(mn[2], mx[2]):
            t = [x, y, z]
            for g, l in cond:
                if t[g] <= t[l]:
                    break
            else:
                ans += 1

print(ans)
