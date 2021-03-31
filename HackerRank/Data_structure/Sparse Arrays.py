from collections import defaultdict

def main():
    n = int(input())
    d=defaultdict(int)
    for i in range(n):
    	x = str(input())
    	d[x]+=1

    q=int(input())
    for i in range(q):
    	x = str(input())
    	print(d[x])



if __name__ == '__main__':
	main()