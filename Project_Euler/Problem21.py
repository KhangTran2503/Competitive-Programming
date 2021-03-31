'''
     Thuat O(n)
'''     

Sum=[1 for i in range(1000001)]
def Era():
	for i in range(2,500001):
			for j in range(i+i,1000001,i):
				Sum[j]+=i




def main():
	Era()
	res=0
	for i in range(1,10000):
		tmp=Sum[i]
		if (tmp > i and Sum[tmp]==i ):
			res+=tmp+i
	print(res)



if __name__ == '__main__':
       main()				