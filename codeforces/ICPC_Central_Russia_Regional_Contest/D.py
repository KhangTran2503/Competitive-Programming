k = int(input())

# all divisor
divisor = [[] for _ in range(k + 1)]
for i in range(1,k + 1):
	for j in range(i,k + 1,i):
		divisor[j].append(i)
# prime
prime = [0,2,3,5,7,11,13,17,19,23,29]

INF = (1 << 1000)
# dp
dp = [[0 for _ in range(11)] for _ in range(k + 1)]

for i in range(1,k + 1):
	dp[i][0] = INF	
for i in range(11):
	dp[1][i] = 1


def fast_pow(x,y):
	ans = 1
	while y:
		if (y & 1):
			ans *= x
		x = x*x
		y >>= 1
	return ans
	
for i in range(2,k + 1):
	for j in range(1,11):
		dp[i][j] = dp[i][j - 1]
		for x in divisor[i]:
			if (x >= 2):
				#print(i,' ',x)
				dp[i][j] = min(dp[i][j],dp[i//x][j - 1]*fast_pow(prime[j],x - 1))

print(dp[k][10])