t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    q = k//(n - 1) - (k % (n - 1) == 0)
    r = k - (n - 1)*q
    ans = r + n*q
    print(ans)