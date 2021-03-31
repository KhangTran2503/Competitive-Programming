import math
n, m = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

ans1 = 1
ans2 = 1
for x in a:
	ans1 *= x
for x in b:
	ans2 *= x
print(ans1//ans2)

