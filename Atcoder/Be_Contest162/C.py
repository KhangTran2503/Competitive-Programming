import math

def calc(N):
    gcd = [[0 for _ in range(N + 1)] for _ in range(N + 1)]

    for i in range(1,N + 1):
        for j in range(i,N + 1):
            gcd[i][j] = math.gcd(i,j)
            gcd[j][i] = gcd[i][j]

    ans = 0
    for i in range(1,N + 1):
        for j in range(1,N + 1):
            for k in range(1,N + 1):
                g = gcd[i][j]
                ans += gcd[g][k]
    return ans


N = int(input())

print(calc(N))




