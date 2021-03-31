
n = int(input())

a = [int(x) for x in input().split()]

pre = 0
ans = 0
for x in a:
    pre += x
    if pre < 0:
        ans += (-pre)
        pre = 0

print(ans)
