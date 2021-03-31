

t = int(input())

for _ in range(t):
    n = int(input())
    if n < 4:
        print(-1)
    else:
        arr = []
        for x in range(1,n + 1,2):
            arr.append(str(x))
        arr = arr[::-1]
        arr.append('4')
        arr.append('2')
        i = 6
        while i <= n:
            arr.append(str(i))
            i += 2
        print(' '.join(arr))

