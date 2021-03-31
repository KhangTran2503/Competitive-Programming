ans = 0

def calc(u,p,lim):
	if u == 0: 
		ans+=1
		return 
	for i in range(1,lim):
		if i**p > u:
			return
		else: calc(u-i**p,p,i)




def main():
	X = int(input())
	n = int(input())
	calc(X,n,100)




if __name__ == '__main__':
	main()

print(ans)	