
a = [int(x) for x in input().split()]

Sum = sum(a)
ok = False
for i in range(0,3):
    for j in range(i + 1,4):
        if 2*(a[i] + a[j]) == Sum:
            ok = True

if ok: print('YES')
else: print('NO')
