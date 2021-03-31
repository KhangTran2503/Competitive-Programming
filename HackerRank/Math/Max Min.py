
def main():
    arr = []
    n = int(input())
    k = int(input())
    for _ in range(n):
    	x = int(input())
    	arr.append(x)

    arr.sort()

    res=1000000000000
    for i in range(n-k+1):
        res = min(res, arr[i+k-1] - arr[i])

    print(res)    	


if __name__ == '__main__':
	main()