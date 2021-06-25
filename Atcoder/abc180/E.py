# dp bitmask

N = int(input())
P = []
for _ in range(N):
	xi,yi,zi = map(int,input().split())
	P.append((xi,yi,zi))


def cost(i,j):
	global P
	#print(i,j,P[i],P[j])
	return abs(P[i][0] - P[j][0]) + abs(P[i][1] - P[j][1]) + max(0,P[j][2] - P[i][2])

if __name__ == '__main__':
	
	INF = 10**15
	dp = [[INF for _ in range(1 << N)] for _ in range(N)]
	
	# for i in range(N):
		# dp[i][1 << i] = 0
	dp[0][1 << 0] = 0
	
	for mask in range(1 << N):
		bit1 = []
		bit0 = []
		for i in range(N):
			if (mask >> i) & 1: bit1.append(i)
			else: bit0.append(i)
		
		if len(bit1) == 0 or len(bit0) == 0: continue
		
		for u in bit1:
			for v in bit0:
				dp[v][mask | (1 << v)] = min(dp[u][mask] + cost(u,v),dp[v][mask | (1 << v)])
	
	
	ans = INF
	for i in range(N):
		ans = min(ans,dp[i][(1 << N) - 1] + cost(i,0))
	
	print(ans)
	
	
