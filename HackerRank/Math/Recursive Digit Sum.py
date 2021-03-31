
def Change(a):
	tmp = 0
	for x in a:
		tmp+=int(x)
	return tmp
	
def calc(a):
	while len(str(a))>1:
		a=Change(str(a))
	return a            


def main():
	n,k = map(int,input().split())
	print(calc(k*calc(n)))


if __name__ == '__main__':
	main()