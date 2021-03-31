n = int(input())
xy = []
ans = 0
for _ in range(n):
	x,y = map(int,input().split())
	for x1,y1 in xy:
		slope = abs((y - y1)/(x - x1))
		if slope <= 1: ans += 1
	xy.append((x,y))

print(ans)