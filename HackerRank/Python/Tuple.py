

def main():
	n = int(input())
	line = map(int, input().split())
	tp = tuple(line)
	print(hash(tp))

if __name__ == '__main__':
	main()