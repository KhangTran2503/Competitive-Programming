


def main():
    n,m=map(int,input().split())
    a=sorted(list(map(int,input().split())))
   
    s=0
    for i in range(len(a)):
        s+=a[i]

    for i in range(n-2,-1,-1):
        if (a[i+1] > a[i]):
            s-=(a[i+1] - a[i])
        else:
    	    s-=1
    	    a[i]=max(a[i+1]-1,1)

    print(s-a[0])			




if __name__ == '__main__':
	main()