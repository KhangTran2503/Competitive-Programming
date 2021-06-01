import numpy as np
import os
import sys
#import string
import subprocess
#import SolutionK

#character = list(string.ascii_letters) + list(string.digits) + ['#','@'] 

# # Generate string with length = l
# def Gen_string(l):
	# s = []
	# for _ in range(l):
		# s.append(np.random.choice(character))
	# return ''.join(s)

# # Generate len
# def Gen_len():
	# p = np.random.randn()
	# if p < 0.4:
		# return np.random.randint(1,10)
	# elif p < 0.8:
		# return np.random.randint(10,25)
	# else:
		# return np.random.randint(25,50)	

# # Gen test with n (mk,tk) and q query
# def Gen_test(n,q):
	# mk = []
	# #inputs = ['{} {}\n'.format(n,q)]
	
	# n_repeat = np.random.randint(n//2,n)
	# n_repeat = max(n_repeat,1)

	# max_len = 0

	# inputs = []
	# for _ in range(n_repeat):
		# s = Gen_string(Gen_len())
		# t = Gen_string(Gen_len())
		# inputs.append('{} {}\n'.format(s,t))
		# mk.append(s)
		# max_len = max(max_len,len(s))

	# if max_len == 0:
		# max_len = 30

	# for _ in range(n_repeat,n):
		# _s = np.random.choice(mk)
		# t = Gen_string(Gen_len())
		# inputs.append('{} {}\n'.format(s,t))

	# np.random.shuffle(inputs)

	# np.random.shuffle(mk)
	# # append query
	# query = []
	# q_min = min(q,len(mk))
	# for i in range(q_min):
		# s = mk[i] + '\n'
		# query.append(s)

	# if q_min + 1 <= q:
		# for _ in range(q_min,q):
			# s = Gen_string(np.random.randint(1,max_len)) + '\n'
			# query.append(s)

	# np.random.shuffle(query)
	# # ------------------
	# inputs = ['{} {}\n'.format(n,q)] + inputs + query
	# return inputs

MAX_NUM = 10**6
MIN_NUM = 1


def subtask1():
	'''
		2 <= N <= 500
		0 <= K <= 1
		30 testcase
		idx: 1 -> 30
	'''
	
	# handle test : 4 test
	# N = 500, K = 0, ai = 1
	N = 500
	K = 0
	data = ' '.join(['1' for _ in range(N)])
	write_test(1,(N,K,data))
	# N = 500, K = 1, ai = 1
	N = 500
	K = 1
	data = ' '.join(['1' for _ in range(N)])
	write_test(2,(N,K,data))
	# N = 500, K = 0, ai = MAX_NUM
	N = 500
	K = 0
	data = ' '.join([str(MAX_NUM) for _ in range(N)])
	write_test(3,(N,K,data))
	# N = 500, K = 1, ai = MAX_NUM
	N = 500
	K = 1
	data = ' '.join([str(MAX_NUM) for _ in range(N)])
	write_test(4,(N,K,data))
	
	# K = 0, ai equal : 4 test
	for idx in range(5,5 + 2):
		K = 0
		N = np.random.randint(2,300)
		ai = np.random.randint(1,MAX_NUM)
		data = ' '.join([str(ai) for _ in range(N)])
		write_test(idx,(N,K,data))
	
	for idx in range(7,7 + 2):
		K = 0
		N = np.random.randint(300,500 + 1)
		ai = np.random.randint(1,MAX_NUM)
		data = ' '.join([str(ai) for _ in range(N)])
		write_test(idx,(N,K,data))
	
	# ai = rand
	for idx in range(9,9 + 4):
		K = 0
		N = np.random.randint(2,500 + 1)
		data = []
		for _ in range(N):
			data.append(np.random.randint(1,MAX_NUM + 1))
		data = ' '.join(map(str,data))
		write_test(idx,(N,K,data))
		
	# K = 1, ai equal : 4 test
	for idx in range(13,13 + 2):
		K = 0
		N = np.random.randint(2,300)
		ai = np.random.randint(1,MAX_NUM + 1)
		data = ' '.join([str(ai) for _ in range(N)])
		write_test(idx,(N,K,data))
	
	for idx in range(15,15 + 2):
		K = 0
		N = np.random.randint(300,500 + 1)
		ai = np.random.randint(1,MAX_NUM + 1)
		data = ' '.join([str(ai) for _ in range(N)])
		write_test(idx,(N,K,data))	
	 
	# K = 1, ai = [1,10^3]: 5 test
	for idx in range(17,17 + 5):
		K = 0
		N = np.random.randint(2,500 + 1)
		data = []
		for _ in range(N):
			data.append(np.random.randint(1,1000))
		data = ' '.join(map(str,data))
		write_test(idx,(N,K,data))
	
	# K = 1, ai = [10^3,10^6]: 9 test
	for idx in range(22,22 + 9):
		K = 0
		N = np.random.randint(2,500 + 1)
		data = []
		for _ in range(N):
			data.append(np.random.randint(1000,MAX_NUM + 1))
		data = ' '.join(map(str,data))
		write_test(idx,(N,K,data))
	
	

def subtask2():
	'''
		2 <= N <= 200
		1 <= K <= 10^9
		1 <= ai <= 100
		idx: 31 -> 75
	'''
	
	# K = 10^9 : 10 test
	K = 10**9
	for idx in range(31,31 + 10):
		N = np.random.randint(50,200 + 1)
		data = []
		for _ in range(N):
			data.append(np.random.randint(1,100 + 1))
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
	
	# K = 10^9, 1 <= ai <= 2: 20 test
	K = 10**9
	for idx in range(41,41 + 10):
		N = np.random.randint(100,200 + 1)
		data = []
		for _ in range(N):
			p = np.random.rand()
			if p < 0.5:
				data.append(1)
			else:
				data.append(2)
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
	
	# K = 2, 100 - 3 <= ai <= 100: 10 test
	K = 2
	for idx in range(51,51 + 10):
		N = np.random.randint(2,200 + 1)
		data = []
		for _ in range(N):
			data.append(np.random.randint(100 - 3,100 + 1))
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
	
	# Rand , K > 2
	K_MAX = 10**9
	for idx in range(61,61 + 15):
		N = np.random.randint(10,200 + 1)
		K = np.random.randint(3,K_MAX)
		data = []
		for _ in range(N):
			data.append(np.random.randint(50,100 + 1))
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
	
def subtask3():
	'''
		2 <= N <= 500
		1 <= K <= 10^9
		1 <= ai <= 10^6
		idx: 76 -> 150
	'''
	# N = rand, K = rand, ai = MAX_NUM: 4 test
	K_MAX = 10**9
	for idx in range(76,76 + 4):
		N = np.random.randint(100,500 + 1)
		K = np.random.randint(MAX_NUM,K_MAX + 1)
		data = ' '.join([str(MAX_NUM) for _ in range(N)]) 
		write_test(idx,(N,K,data))
		
	# N = rand, K = rand , ai = 1000 : 4 test
	K_MAX = 10**9
	for idx in range(80,80 + 4):
		N = np.random.randint(50,300 + 1)
		K = np.random.randint(MAX_NUM,K_MAX + 1)
		data = ' '.join([str(1000) for _ in range(N)]) 
		write_test(idx,(N,K,data))
	# N = 500, K = 10**9, ai = MAX_NUM
	K = 10**9
	N = 500 
	data = ' '.join([str(MAX_NUM) for _ in range(500)])
	write_test(84,(N,K,data))
	# N = 500, K = 1, ai = MAX_NUM
	K = 1
	N = 500 
	data = ' '.join([str(MAX_NUM) for _ in range(500)])
	write_test(85,(N,K,data))
	
	# K = 10**9, N = 500, ai = [1000,10^4]: 10 test
	N = 500
	K = 10**9
	for idx in range(86,86 + 10):
		data = []
		for _ in range(N):
			data.append(np.random.randint(1000,10000 + 1))
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
	
	# K = 10**9, N = 500, ai = [5*10^4,10^6]: 10 test
	N = 500
	K = 10**9
	for idx in range(96,96 + 10):
		data = []
		for _ in range(N):
			data.append(np.random.randint(50000,MAX_NUM + 1))
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
	
	# K = rand, N = rand, ai = [1,100]
	MAX_K = 10**9
	for idx in range(106,106 + 5):
		N = np.random.randint(10,400 + 1)
		K = np.random.randint(MAX_K)
		data = []
		for _ in range(N):
			data.append(np.random.randint(1,100 + 1))
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
	
	# K = rand, N = rand, ai = [100,1000]
	MAX_K = 10**9
	for idx in range(111,111 + 10):
		N = np.random.randint(50,200 + 1)
		K = np.random.randint(MAX_K)
		data = []
		for _ in range(N):
			data.append(np.random.randint(100,1000 + 1))
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
	
	# K = rand, N = rand, ai = [100,1000]
	MAX_K = 10**9
	for idx in range(121,121 + 10):
		N = np.random.randint(300,500 + 1)
		K = np.random.randint(MAX_K)
		data = []
		for _ in range(N):
			data.append(np.random.randint(10000,100000 + 1))
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
	
	# K = rand, N = rand, ai = [100000,1000000]
	MAX_K = 10**9
	for idx in range(131,131 + 20):
		N = np.random.randint(350,500 + 1)
		K = np.random.randint(MAX_K)
		data = []
		for _ in range(N):
			data.append(np.random.randint(100000,MAX_NUM))
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
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
	
	# Run test
	#subtask1()
	subtask2()
	#subtask3()