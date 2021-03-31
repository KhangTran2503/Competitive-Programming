




t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    
    Sum = [0]*(n + 1)
    cnt = [0]*(8001)

    for i in range(n):
        Sum[i + 1] = Sum[i] + a[i]

    for i in range(n):
        for j in range(i + 2,n + 1):
            if Sum[j] - Sum[i] <= 8000:
                cnt[Sum[j] - Sum[i]] += 1

    ans = 0
    for x in a:
        ans += int(cnt[x] > 0)
    print(ans)

