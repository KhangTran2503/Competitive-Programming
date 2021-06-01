
def solve():
	n = int(input())
	stack = []
	for _ in range(n):
		x = int(input())
		if x > 1:
			while (len(stack) > 0) and (stack[-1] + 1 != x):
				stack.pop()
				
			if len(stack) > 0: stack.pop()
			
		stack.append(x)
		print('.'.join(map(str,stack)))
		
	

if __name__ == '__main__':
	T = int(input())
	for _ in range(T):
		solve()