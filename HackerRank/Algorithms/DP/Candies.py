
def main():
	arr = []
	n = int(input())
	for _ in range(n):
		x = int(input())
		arr.append(x)


	l = [0]*n
	l[0] = 1
	for i in range(1,n,1):
		if (arr[i] > arr[i-1]): l[i] = l[i-1] + 1
		else: l[i] = 1

	res = l[n-1]
	for i in range(n-2,-1,-1):
		if (arr[i] > arr[i+1] and l[i] <= l[i+1]): l[i] = l[i+1] + 1
		res += l[i]
	print(res)

if __name__ == '__main__':
	main()
