import math

def calc(n,m):
	m*=2
	u = int(math.sqrt(m))
	if u*(u+1) <= m: u+=1
	return min(n,u)


def main():
	t = int(input())
	for _ in range(t):
		n,m = map(int,input().split())
		print(calc(n,m))

if __name__ == '__main__':
	main()