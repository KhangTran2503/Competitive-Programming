

def process(a,n):
    left , right = 0, n - 1
    cur = 0
    ans = ''
    while (1):
        if (max(a[left], a[right]) <= cur): break

        if (a[left] == a[right]):
            l = left + 1
            while (l <= right and a[l] > a[left]): l += 1
            r = right - 1
            while (r >= left and a[r] > a[right]): r -= 1
            if (l - left > right - r):
                ans += 'L'*(l - left)
            else:
                ans += 'R'*(right - r)
            break

        Min = min(a[left], a[right])
        if (Min > cur):
            if (a[left] > a[right]):
                cur = max(cur, a[right])
                ans += 'R'
                right -= 1
            else :
                cur = max(cur, a[left])
                ans += 'L'
                left += 1
        else :
            if (a[left] > a[right]):
                cur = max(cur, a[left])
                ans += 'L'
                left += 1
            else :
                cur = max(cur, a[right])
                ans += 'R'
                right -= 1

    print(len(ans))
    print(ans)



def main():
    n = int(input())
    a = list(map(int,input().split()))
    process(a,n)

if __name__ == '__main__':
    main()
