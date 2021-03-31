


def main():
    N1 = int(input())
    l1 = list(map(int,input().split()))

    N2 = int(input())
    l2 = list(map(int,input().split()))

    S1 = set(l1)
    S2 = set(l2)

    Ans = S1 ^ S2
    for x in list(Ans) : print(x)

if __name__ == '__main__':
	main()
