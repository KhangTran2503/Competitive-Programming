x=[]
y=[]

def check(n):
	ok1=True
	ok2=True

	for i in range(1,n):
		if (x[i]!=x[i-1]):
	
			ok1=False
	for i in range(1,n):
		if (y[i]!=y[i-1]):
			ok2=False


	return (ok1 or ok2)


def main():
	n=int(input())
	for i in range(n):
		xx,yy=map(int,input().split())
		x.append(xx)
		y.append(yy)

	if (check(n)):
		print('YES')
	else:
		print('NO')	


if __name__ == '__main__':
	main()