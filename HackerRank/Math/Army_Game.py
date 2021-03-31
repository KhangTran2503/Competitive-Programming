n,m=map(int,input().split())

res=0
res=(n//2)*(m//2)
nn=n%2
mm=m%2
if (nn==1 and mm==1):
	res+=1+(n-1)//2+(m-1)//2
if (nn==1 and mm==0):
	res+=(m)//2
if (nn==0 and mm==1):
	res+=n//2

print(res)	