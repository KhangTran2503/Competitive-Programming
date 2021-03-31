
def change(n):
    while (n % 10 == 0): n //= 10
    return n


n = int(input())
f = dict()

f[n] = 1
while (1):
    n = change(n + 1)
    if (f.get(n) != None): break
    else: f[n] = 1

print(len(f))
