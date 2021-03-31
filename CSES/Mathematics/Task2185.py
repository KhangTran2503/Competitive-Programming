n, k = map(int,input().split())
a = list(map(int,input().split()))


ans = 0
for msk in range(1,1 << k):
	cnt_bit = 0
	LCM = 1
	for i in range(k):
		if (msk >> i) & 1 == 1:
			LCM *= a[i]
			cnt_bit += 1
	if (cnt_bit & 1 == 1):
		ans += (n//LCM)
	else:
		ans -= (n//LCM)

print(ans)