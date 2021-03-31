
Mod = 10**10


ans = 0

for i in range(1,1001):
    t = 1
    for j in range(1,i + 1):
        t  = (t*i) % Mod
    ans = (ans + t) % Mod

print(ans)
