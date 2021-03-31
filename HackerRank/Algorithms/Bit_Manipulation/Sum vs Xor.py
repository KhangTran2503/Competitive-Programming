
def main():
	n = int(input())
	if n==0 : print(1)
	else : print(1<<bin(n)[2:].count('0'))


if __name__ == '__main__':
	main()