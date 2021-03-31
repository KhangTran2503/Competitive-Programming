

def calc(x) :

    res = 0
    if (x % 2 == 0) :
        x //= 2
        u = (x // 4) * 4
        for i in range(u, u + (x % 4) + 1, 1) :
            res ^= (2*i)
    else :
        u = x - 1
        u //= 2
        _u = (u // 4) * 4
        for i in range(_u, _u + (u % 4) + 1, 1) :
            res ^= (2*i + 1)

    return res

# A1 = 1
# A2 = 1 ^ 2
# A3 = 1 ^ 2 ^ 3
#.........
# An = 1 ^ 2 ^ 3 ^ ...... ^ n
# if n is even res = 2 ^ 4 ^ 6 ^.... ^ n
# if n is odd res = 1 ^ 3 ^ 5 ^ .....^ n


def main() :
    Q = int(input())
    for _ in range(Q) :
        l, r = map(int,input().split())
        print(calc(r) ^ calc(l-1))



if __name__ == '__main__' :
    main()
