#tinh 2nCn
def calc():
	res1=1
	res2=1
	for i in range(1,21):
		res1*=(20+i)
		res2*=i
	print(res1//res2)
	
calc()