import math 

def lcm(a,b):
    return (a//math.gcd(a,b))*b


n = int(input())

a = [int(x) for x in input().split()]

ans = 0

pregcd = [0]*n
pregcd[0] = a[0]

for i in range(1,n):
    pregcd[i] = math.gcd(pregcd[i - 1],a[i])

for i in range(1,n):
    ans = math.gcd(ans,lcm(a[i],pregcd[i - 1]))
print(ans)



