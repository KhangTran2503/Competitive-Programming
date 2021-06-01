import os
import sys
import glob
import subprocess
dir_test = './Test'

def score(src,num_file):
	if '.cpp' in src:
		subprocess.call(['g++ -std=c++11 -O2 {} -o run'.format(src)],shell=True)
		dir_input = os.path.join(dir_test,'in')
		dir_output = os.path.join(dir_test,'out')
		
		cnt = 0
		for index in range(1,num_file + 1):
			file_input = 'input' + str(index) + '.txt'
			file_output = 'output' + str(index) + '.txt'
			file_pathin = os.path.join(dir_input,file_input)
			file_pathout = os.path.join(dir_output,file_output)
			with open("./out.txt", "w") as f:
				subprocess.call(['./run'],stdin=open(file_pathin, "r"),stdout=f)
			
			diff = os.system('diff -rqbw {} {}'.format('./out.txt',file_pathout))
			if diff == 0: cnt += 1
			
		return round((cnt/num_file)*100,2)
	
	if '.py' in src:
		#subprocess.call(['g++ -std=c++11 -O2 {} -o run'.format(src)],shell=True)
		dir_input = os.path.join(dir_test,'in')
		dir_output = os.path.join(dir_test,'out')
		
		cnt = 0
		for index in range(1,num_file + 1):
			file_input = 'input' + str(index) + '.txt'
			file_output = 'output' + str(index) + '.txt'
			file_pathin = os.path.join(dir_input,file_input)
			file_pathout = os.path.join(dir_output,file_output)
			#with open("./out.txt", "w") as f:
			subprocess.call(['python3 {} < {} > {}'.format(src,file_pathin,'./out.txt')],shell=True)
			
			diff = os.system('diff -rqbw {} {}'.format('./out.txt',file_pathout))
			if diff == 0: cnt += 1
			
		return round((cnt/num_file)*100,2)
		
	raise Exception('!!!')

if __name__ == '__main__':
	argv = sys.argv[2:]
	num_file = int(sys.argv[1])
	for src in argv:
		print('{} : {}'.format(src,score(src,num_file)))
		