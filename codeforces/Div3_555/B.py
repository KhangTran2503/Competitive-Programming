
def change(a,f,n):
    a = list(a)
    for i in range(n):
        u = int(a[i])
        if u < f[u - 1]:
            j = i
            while (j < n):
                x = int(a[j])
                if (x <= f[x - 1]):
                    a[j] = str(f[x - 1])
                    j += 1
                else: break
            break
    print(''.join(x for x in a))


def main():
    n = int(input())
    a = input()
    f = list(map(int,input().split()))
    change(a,f,n)

if __name__ == '__main__':
    main()
