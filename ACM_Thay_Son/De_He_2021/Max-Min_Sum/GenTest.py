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

MAX_NUM = 10**9
MIN_NUM = -MAX_NUM


def subtask1():
	'''
		2 <= N, K <= 24
		15 testcase
	'''
	N_MAX = 24
	N_MIN = 2
	K_MAX = 24
	K_MIN = 2
	
	# handle test : 1 test
	# N = K = 2
	data = '{} {}'.format(MAX_NUM,MIN_NUM)
	write_test(1,(2,2,data))
	
	# Ai equal : 1 test
	# N = 24, K = 12
	data = ' '.join([str(MIN_NUM) for _ in range(24)])
	write_test(2,(24,12,data))
	
	# Ai = MIN or MAX : 3 test
	for idx in range(3,3 + 3):
		N = np.random.randint(8,N_MAX + 1)
		K = np.random.randint(K_MIN,N//2)
		data = []
		for _ in range(N):
			p = np.random.rand()
			if p < 0.5:
				data.append(MAX_NUM)
			else:
				data.append(MIN_NUM)
		data = ' '.join(map(str,data))
		write_test(idx,(N,K,data))
		
	# Random: 10 test
	for idx in range(6,10 + 1):
		N = N_MAX - (idx - 6)
		K = np.random.randint(K_MIN,N + 1)
		data = []
		for _ in range(N):
			data.append(np.random.randint(MIN_NUM,MAX_NUM + 1))
		
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
		
	for idx in range(11,15 + 1):
		N = 8 + (idx - 11)
		K = np.random.randint(K_MIN,N + 1)
		data = []
		for _ in range(N):
			data.append(np.random.randint(0,10000 + 1))
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))

def subtask2():
	'''
		2 <= N, K <= 1000
	'''
	K_MIN = 2
	N_MIN = 2
	
	
	# N in [100,500] : 20 test
	for idx in range(16,16 + 20):
		N = np.random.randint(100,500 + 1)
		K = np.random.randint(K_MIN,N)
		data = []
		for _ in range(N):
			data.append(np.random.randint(-1000,10000 + 1))
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
	
	# N in [500,1000] : 20 test
	for idx in range(36,36 + 20):
		N = np.random.randint(500,1000 + 1)
		K = np.random.randint(K_MIN,N//2)
		data = []
		for _ in range(N):
			data.append(np.random.randint(-1000,MAX_NUM))
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
	
	# N in [25,100] : 10 test
	for idx in range(56,56 + 10):
		N = np.random.randint(25,100 + 1)
		K = np.random.randint(K_MIN,N//2)
		data = []
		for _ in range(N):
			data.append(np.random.randint(-100,1000))
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
	
	# N in [500,1000], ai in [MAX_NUM,MIN_NUM]
	for idx in range(66,66 + 10):
		N = np.random.randint(500,1000 + 1)
		K = np.random.randint(K_MIN,N)
		data = []
		for _ in range(N):
			p = np.random.rand()
			if p < 0.5:
				data.append(MAX_NUM)
			else:
				data.append(MIN_NUM)
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
	
def subtask3():
	'''
		2 <= N,K <= 10^5
	'''
	# N = 10^5, K = N/2: 10 test
	for idx in range(76,76 + 10):
		N = 100000
		K = N//2
		data = []
		for _ in range(N):
			data.append(np.random.randint(-100,MAX_NUM + 1))
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
		
	# N = 10^5 , K = N/2, ai = [MIN_NUM, MAX_NUM] : 10test
	for idx in range(86,86 + 10):
		N = 100000
		K = N//2
		data = []
		for _ in range(N):
			p = np.random.rand()
			if p < 0.5:
				data.append(MAX_NUM)
			else:
				data.append(MIN_NUM)
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
	
	# N = [10^4,10^5] , K = N/2 : 20 test
	for idx in range(96,96 + 20):
		N = np.random.randint(10000,100000)
		K = N//2
		data = []
		for _ in range(N):
			data.append(np.random.randint(-1000,MAX_NUM + 1))
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
	
	# N = [10^4,10^5] : 20 test
	for idx in range(116,116 + 20):
		N = np.random.randint(10000,100000)
		K = np.random.randint(2,N)
		data = []
		for _ in range(N):
			data.append(np.random.randint(-1000,100000))
		data = ' '.join(map(str,data)) 
		write_test(idx,(N,K,data))
	
	# N = [10^3,10^4]
	for idx in range(136,136 + 15):
		N = np.random.randint(5000,10000)
		K = np.random.randint(2,N)
		data = []
		for _ in range(N):
			data.append(np.random.randint(-1000,1000))
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
	#subtask2()
	#subtask3()