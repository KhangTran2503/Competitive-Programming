prime = []

def Era():
	okprime = [0 for i in range(101)]
	for i in range(2,11):
		if okprime[i] == 0:
			for j in range(i*i,101,i):
				okprime[j] = 1

	for i in range(2,101):
	    if okprime[i] == 0:
	        prime.append(i)			

def main():
	Era()
	q = int(input())
	for _ in range(q):
		n = int(input())
		res = 1
		ans = 0
		for i in range(len(prime)):
		    res*=prime[i]
		    if res <= n:
		    	ans=i+1
		    else : break
		
		print(ans)    	



if __name__ == '__main__':
	main()