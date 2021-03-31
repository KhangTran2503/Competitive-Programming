import math

def Pow(x,y):
	ans = 1
	while (y):
		if (y&1): ans*=x
		x = x*x
		y>>=1
	return ans	


def Find(L,R,p):
	l = 1 
	r = 100000000000
	while l <= r:
		mid = (l+r)//2
		tmp = Pow(mid,p)
		if tmp >= L and tmp<=R:
			return 1
		elif tmp < L:
			l = mid+1
		else:
			r = mid-1
	return 0		 		



def main():
	q = int(input())
	for i in range(q):
		l,r = map(int,input().split())
		ans = 1
		for k in range(33,0,-1):
			if Find(l,r,k):
				ans = k
				break
		print("Case #"+str(i+1)+": "+str(ans))		






if __name__ == '__main__':
	main()