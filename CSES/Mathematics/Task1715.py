Mod = 1000000007

def fastpow(x,y,MOD):
    ans = 1
    while y:
        if (y & 1): ans = (ans * x) % MOD
        x = (x * x) % MOD
        y >>= 1
    return ans


s = input()
n = len(s)

cnt = [0 for _ in range(26)]
for x in s:
    cnt[ord(x) - ord('a')] += 1

fac = [1 for _ in range(n + 1)]
ifac = [1 for _ in range(n + 1)]
for i in range(1,n + 1):
    fac[i] = (fac[i - 1]*i) % Mod

ifac[n] = fastpow(fac[n],Mod - 2,Mod)
for i in range(n - 1,-1,-1):
    ifac[i] = (ifac[i + 1]*(i + 1)) % Mod

res = fac[n]
for i in range(26):
    res = (res*ifac[cnt[i]]) % Mod

print(res)



