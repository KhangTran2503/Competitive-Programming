INF = 1000000000000

cnt = [-INF for _ in range(200001)]
n = int(input())

ok = True
for _ in range(n):
    a, c = map(int,input().split())
    if cnt[c] > a:
        ok = False
    else: cnt[c] = a

if ok: print('YES')
else: print('NO')

