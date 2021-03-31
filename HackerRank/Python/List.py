arr=[]

def process(a=[]):
	if (a[0]=='print'):
		print(arr)
		return
	
	if (a[0]=='sort'):
		arr.sort()
		return	
	
	if (a[0]=='pop'):
		arr.pop()
		return

	if (a[0]=='reverse'):
		arr.reverse()	
		return

		
	if (a[0]=='remove'):
		arr.remove(int(a[1]))
		return

	if (a[0]=='append'):
		arr.append(int(a[1]))
		return 

	if (a[0]=='insert'):
		arr.insert(int(a[1]),int(a[2]))		
		return
		



def main():
  	n=int(input())
  	for i in range(n):
  		x=map(str,input().split())
  		x=list(x)
  		process(x)
  		
       

if __name__ == '__main__':
	main()