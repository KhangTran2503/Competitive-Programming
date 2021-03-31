oo = 100000000000000000000

def cost(x):
    tmp = 0
    tmp += (x // 5)
    x %= 5
    tmp += (x // 2)
    x %= 2
    tmp += x
    return tmp


def solve(A, n) :
    M = min(A)
    res = oo
    for t in range(M - 4, M + 1, 1):
        delta = 0
        for x in A :
            delta += cost(x - t)

        res = min(res, delta)

    return res


def main() :
    T = int(input())
    for _ in range(T) :
        n = int(input())
        a = list(map(int,input().split()))
        print(solve(a,n))



if __name__ == '__main__' :
    main()
