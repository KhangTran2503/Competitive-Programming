import math

T = int(input())

for _ in range(T):
	s = input()
	t = input()
	n = len(s)
	m = len(t)
	lcm = m*n//math.gcd(m,n)
	s *= (lcm//n)
	t *= (lcm//m)
	if s == t: print(s)
	else: print(-1)