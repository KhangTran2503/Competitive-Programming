
if __name__ == '__main__':
	N = int(input())
	a = map(int,input().split())
	a = [0] + list(a)

	dp = [0 for _ in range(N + 1)]
	sumodd = [0 for _ in range(N + 1)]
	
	sumodd[1] = a[1]
	for i in range(3,N + 1,2):
		sumodd[i] = sumodd[i - 2] + a[i]
	
	
	for i in range(2,N + 1):
		if (i & 1):
			dp[i] = max(dp[i - 1],dp[i - 2] + a[i])
		else:
			dp[i] = max(dp[i - 2] + a[i],sumodd[i - 1]) 
	
	print(dp[N])
