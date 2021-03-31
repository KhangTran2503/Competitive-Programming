n = int(input())
A = []
sumA = 0
AB = []
for _ in range(n):
	a, b = map(int,input().split())
	sumA += a
	AB.append(2*a + b)

AB.sort(reverse=True)

ans = 0
sumAB = 0
while ans < len(AB) and sumAB <= sumA:
	sumAB += AB[ans]
	ans += 1

print(ans)