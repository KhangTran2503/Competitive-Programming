
def main():
    n, m = map(int,input().split())
    Sum = 0
    for _ in range(m):
        a,b,k = map(int,input().split())
        Sum += k*(b-a+1)

    print(Sum//n)


main()
