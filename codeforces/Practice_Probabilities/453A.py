m, n = map(int,input().split())

ans = (1/m)**n
for i in range(2,m + 1):
	ans += i*((i/m)**n - ((i - 1)/m)**n)

print(round(ans,6))
