import numpy as np
import os
import sys
#import string
import subprocess
#import SolutionK



MAX_Q = 10**5
MAX_P = 10**5
prime = []

def init():
	ok_prime = [0 for _ in range(MAX_P + 1)]
	for i in range(2,MAX_P + 1):
		if ok_prime[i] == 0:
			prime.append(i)
			for j in range(i*i,MAX_P + 1,i):
				ok_prime[j] = 1

def subtask1():
	'''
		1 <= Q <= 10^5
		1 <= N <= 1000
		2 <= p <= 10^5. p is prime
		30 testcase
		idx: 1 -> 30
	'''
	
	# handle test : 2 test
	# Q = 10^5, N = [100,1000], p = Max_prime
	Q = MAX_Q
	data = []
	for _ in range(Q):
		data.append(np.random.randint(100,1000 + 1))
	data = '\n'.join(map(str,data))
	write_test(1,(Q,prime[-1],data))
	
	# N = 500, K = 1, ai = 1
	Q = 10
	data = []
	for _ in range(Q):
		data.append(np.random.randint(100,1000 + 1))
	data = '\n'.join(map(str,data))
	write_test(2,(Q,prime[-1],data))
	
	
	# Q <= 10^3, N <= 1000, P | N : 10 test
	for idx in range(3,3 + 10):
		Q = np.random.randint(1,1000 + 1)
		P = np.random.choice(prime)
		data = []
		for _  in range(Q):
			if P > 1000:
				N = np.random.randint(1,1000 + 1)
			else:
				div = N//P
				N = np.random.randint(1,div + 1)*P
			data.append(N)
		
		data = '\n'.join(map(str,data))
		write_test(idx,(Q,P,data))
	
	# Q = [10^3,10^5], N <= 1000: 18 test
	for idx in range(13,13 + 18):
		Q = np.random.randint(1000,MAX_Q + 1)
		P = np.random.choice(prime)
		data = []
		for _ in range(Q):
			data.append(np.random.randint(1,1000 + 1))
		data = '\n'.join(map(str,data))
		write_test(idx,(Q,P,data))
	
	

def subtask2():
	'''
		1 <= Q <= 10^5
		1 <= N < P
		idx: 31 -> 75
	'''
	idx_P = 0
	for i in range(len(prime)):
		if prime[i] >= 10000:
			idx_P = i
			break
	
	
	
	# P = 2, N = 1, Q = 1: 1 test
	P = 2
	Q = 1
	data = '1'
	write_test(31,(Q,P,data))
	
	# P = P_MAX , n = [P/3,P): 20 test
	for idx in range(32,32 + 20):
		Q = np.random.randint(1,MAX_Q + 1)
		P = prime[-1]
		data = []
		for _ in range(Q):
			data.append(np.random.randint(P//3,P))
		data = '\n'.join(map(str,data))
		write_test(idx,(Q,P,data))
	
	# Rand all N >= 10000
	for idx in range(52,52 + 24):
		Q = np.random.randint(1000,MAX_Q + 1)
		P = prime[np.random.randint(idx_P,len(prime))]
		data = []
		for _ in range(Q):
			data.append(np.random.randint(5000,P))
		data = '\n'.join(map(str,data))
		write_test(idx,(Q,P,data))
	
def subtask3():
	'''
		1 <= Q <= 10^5
		2 <= P <= 10^5
		1 <= N <= 10^12
		idx: 76 -> 150
	'''
	# N = [10^5,10^6]: 20 test
	for idx in range(76,76 + 20):
		Q = np.random.randint(1,1000)
		P = np.random.choice(prime)
		data = []
		for _ in range(Q):
			N = np.random.randint(100000,1000001)
			N = (N//P + 1)*P
			data.append(N)
		data = '\n'.join(map(str,data))
		write_test(idx,(Q,P,data))
		
	# N = P, Q = 1: 10 test
	for idx in range(96,96 + 10):
		Q = 1
		P = np.random.choice(prime)
		data = str(P) 
		write_test(idx,(Q,P,data))
	
	# N = [10^6,10^8]: 20 test
	for idx in range(106,106 + 20):
		Q = np.random.randint(1000,100000)
		P = np.random.choice(prime)
		data = []
		for _ in range(Q):
			N = np.random.randint(10**6,10**8)
			data.append(N)
		data = '\n'.join(map(str,data))
		write_test(idx,(Q,P,data))
	
	# N = [10^9,10^12]: 20 test
	for idx in range(126,126 + 25):
		Q = np.random.randint(50000,100000)
		P = np.random.choice(prime)
		data = []
		for _ in range(Q):
			N = np.random.randint(10**9,10**12 + 1)
			data.append(N)
		data = '\n'.join(map(str,data))
		write_test(idx,(Q,P,data))
	#pass
	
	
def write_test(index, inputs):
	dir_name =  './Test'
	if not os.path.exists(dir_name):
		os.mkdir(dir_name)
	
	dir_input = os.path.join(dir_name,'in')
	if not os.path.exists(dir_input):
		os.mkdir(dir_input)
		
	dir_output = os.path.join(dir_name,'out')
	if not os.path.exists(dir_output):
		os.mkdir(dir_output)
		
	file_input = 'input' + str(index)
	file_output = 'output' + str(index)
	file_pathin = os.path.join(dir_input,file_input)
	#print(filepath)
	file_pathout = os.path.join(dir_output,file_output)
	
	with open(file_pathin + ".txt", "w") as f:
		f.write('{} {}\n{}'.format(inputs[0],inputs[1],inputs[2]))

	'''
	with open(filepathout + ".txt", "w") as f:
		ans = SolutionK.Answer(s,k,index)
		f.write("{}".format(ans))
	'''

	# Using code C++
	with open(file_pathout + ".txt", "w") as f:
		subprocess.call(['./run'],stdin=open(file_pathin + ".txt", "r"),stdout=f)
	print('###--DONE--{}'.format(index))
	
if __name__ == '__main__':
	# Run file C++
	subprocess.call(['g++ -std=c++11 -O2 solution.cpp -o run'],shell=True)
	init()
	# Run test
	#subtask1()
	#subtask2()
	subtask3()