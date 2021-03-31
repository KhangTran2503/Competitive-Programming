a,b = map(int,input().split())

def fast_pow(x,y):
	ans = 1
	while y:
		if (y & 1): ans = ans*x
		x = x*x
		y >>= 1
	return ans

ans = 0
lo = 1
hi = fast_pow(10,18)
while lo <= hi:
	mid = (lo + hi) >> 1
	tmp1 = fast_pow(a,mid)
	tmp2 = fast_pow(mid,b)
	if tmp1 == tmp2:
		ans = mid
		break
	elif tmp1 > tmp2:
		hi = mid - 1
	else:
		lo = mid + 1
print(ans)