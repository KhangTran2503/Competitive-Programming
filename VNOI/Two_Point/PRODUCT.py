
def main():
	P = int(input())

	
	res = 1
	j = 1
	for i in range(1,100001):
		res *= i
		while j<i and P<res:
			res//=j
			j += 1

		if (res == P):
			print(j,end=' ')
			print(i)
			return






if __name__ == '__main__':
	main()