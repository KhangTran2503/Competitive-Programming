import math
n, m, h = map(int,input().split())
s = list(map(int,input().split()))

Sum = sum(s)

sum1 = Sum - 1
sum2 = Sum - s[h - 1]

if (n - 1 > sum1):
	print(-1)

elif (n - 1 > sum2):
	print(1)
else:
	#ans = 1 - C(sum2,n - 1)/C(sum1,n - 1)
	# math.log
	ans = 0
	for i in range(sum2 - n + 2,sum2 + 1):
		ans += math.log(i)
	
	for i in range(sum1 - n + 2,sum1 + 1):
		ans -= math.log(i)
	
	ans = 1 - math.exp(ans)
	print(round(ans,8))
