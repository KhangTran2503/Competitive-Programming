
def main():
    T = int(input())
    for _ in range(T):
    	n = int(input())
    	ls = map(int, input().split())
    	arr = list(ls)
    	res = 1
    	for x in arr:
    		res = (res*x) % 1234567

    	print(res)	

if __name__ == '__main__':
	main()