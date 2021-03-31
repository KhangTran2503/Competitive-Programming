
def check(N,K):
    while N % K == 0:
        N //= K
    return (N % K == 1)

def divisor(N):
    d = []
    K = 1
    while K*K <= N:
        if N % K == 0:
            d.append(K)
            if K*K != N:
                d.append(N//K)
        K += 1
    #ans += (N - 1)//K
    return d


N = int(input())

divi = divisor(N)

ans = 0

for x in divi:
    if x > 1:
        ans += int(check(N,x))

ans += len(divisor(N - 1)) - 1
print(ans)

