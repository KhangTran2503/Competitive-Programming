
def isprime(x):
    if x < 2: return False
    i = 2
    while i*i <= x:
        if x % i == 0: return False
        i += 1
    return True



def consecutive_len(a,b):
    x = 0
    f = lambda x: x**2 + a*x + b

    while isprime(f(x)): x += 1
    return x
    

prime_b = list(filter(isprime,range(2000)))
lenb = len(prime_b)

maxlen = 0 
for b in prime_b:
    if b > 1000: break
    for a in range(-1000,1001,1):
        clen = consecutive_len(a,b)
        if clen > maxlen: 
            maxlen = clen
            ans = (a,b)

print(ans)
print(ans[0]*ans[1])
