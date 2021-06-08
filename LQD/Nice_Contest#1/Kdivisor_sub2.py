import math

def check_square(x):
	sqrt_x = int(math.sqrt(x))
	while (sqrt_x*sqrt_x < x): sqrt_x += 1
	return sqrt_x

if __name__ == '__main__':
	# K = int(input())
	# T = int(input())
	
	MaxN = 10**6 + 5
	divisor = [0 for _ in range(MaxN)]
	
	for i in range(1,MaxN):
		for j in range(i,MaxN,i):
			divisor[j] += 1
	
	
	for i in range(1,MaxN):
		if divisor[i] % 2 == 1:
			j = check_square(i)
			if divisor[j]*divisor[j] - 1 != divisor[i]:
				print(i,j)
				
	# for _ in range(T):
		# solve()
