from sys import stdin,stdout

def dp(s,t):
    m = len(s)
    n = len(t)
    
    f = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

    for i in range(m + 1): f[i][0] = i
    for i in range(n + 1): f[0][i] = i

    for i in range(m):
        for j in range(n):
            if s[i] == t[j]: f[i + 1][j + 1] = f[i][j]
            else: f[i + 1][j + 1] = min(f[i][j + 1],f[i][j],f[i + 1][j]) + 1
    return f[m][n]



s = stdin.readline().strip()
t = stdin.readline().strip()
print(dp(s,t))
