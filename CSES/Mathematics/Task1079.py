Mod = 1000000007

def fastpow(a,b,modu):
    ans = 1
    while b > 0:
        if (b & 1): ans = (ans * a) % modu
        a = (a * a) % modu
        b >>= 1
    return ans


MaxN = 1000005

fac = [1 for _ in range(MaxN)]
ifac = [1 for _ in range(MaxN)]


for i in range(1,MaxN):
    fac[i] = (fac[i - 1]*i) % Mod

ifac[MaxN - 1] = fastpow(fac[MaxN - 1],Mod - 2,Mod)
for i in range(MaxN - 2,-1,-1):
    ifac[i] = ((i + 1)*ifac[i + 1]) % Mod



def C(r,n):
    global Mod
    global fac
    global ifac
    ans = fac[n]
    ans = (ans*ifac[r]) % Mod
    ans = (ans*ifac[n - r]) % Mod
    return ans

if __name__ == '__main__':

    n = int(input())
    for _ in range(n):
        a, b = map(int,input().split())
        print(C(b,a))
