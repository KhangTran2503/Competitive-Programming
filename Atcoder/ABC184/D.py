A, B, C = map(int,input().split())

E = dict()

for i in range(100,A - 1,-1):
	for j in range(100,B - 1,-1):
		for k in range(100,C - 1,-1):
			if (i == 100) or (j == 100) or (k == 100):
				E[(i,j,k)] = 0
			else:
				sample = i + j + k
				if sample == 0: continue
				E[(i,j,k)] = (i/sample)*E[(i + 1,j,k)] + (j/sample)*E[(i,j + 1,k)] + (k/sample)*E[(i,j,k + 1)] + 1

print(round(E[(A,B,C)],10))
			
