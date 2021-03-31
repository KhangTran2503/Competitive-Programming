
def main():
	q = int(input())
	for _ in range(q):
		n = int(input())
		a = []
		for i in range(n):
			lis = map(int,input().split())
			arr = list(lis)
			a.append(arr)

		contain = [0 for i in range(n)] #tim so luong cac contain chua dc
		ball = [0 for i in range(n)]	# so luong cac ball hien co	
		for i in range(n):
			for j in range(n):
				contain[i] += a[i][j]
				ball[j] += a[i][j]

		contain.sort()
		ball.sort()
		if contain == ball : #neu tuong ung tung vi tri thi co the bo dc 
			print("Possible")
		else:
			print("Impossible")			
					


if __name__ == '__main__':
	main()