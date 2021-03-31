

def main():
    n = int(input())
    arr = []
    for _ in range(n):
        x = int(input())
        arr.append(x)

    for i in sorted(arr):
	       print(i)

main()
