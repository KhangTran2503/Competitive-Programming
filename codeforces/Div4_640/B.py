t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    if n % 2 == 0:
        if k % 2  == 0:
            if n >= k:
                print('YES')
                for _ in range(k - 1):
                    print(1,end = ' ')
                print(n - k + 1)
            else: print('NO')
        else: 
            if n >= 2*k:
                print('YES')
                for _ in range(k - 1):
                    print(2,end = ' ')
                print(n - 2*(k - 1))
            else: print('NO')
    else: 
        if k % 2 == 0: print('NO')
        else: 
            if n >= k:
                print('YES')
                for _ in range(k - 1):
                    print(1,end = ' ')
                print(n - k + 1)
            else: print('NO')

