


t = int(input())


for _ in range(t):
    n0,n1,n2 = map(int,input().split())
    s = ''
    if n1 % 2 == 1:
        r = (n1 + 1) >> 1
        s = '01'*r
        s = '0'*n0 + s
        s = s + '1'*n2
    else:
        if n1 > 0:
            r = (n1 >> 1)
            if n0 > 0:
                s = '10'*r
                s = s + '0'*n0 + '1' 
                s = '1'*n2 + s
            else:
                s = '01'*r
                s = s + '1'*n2 + '0'
                s = '0'*n0 + s

        else:
            s = ''
            if n0 > 0:
                s = '0'*(n0 + 1)
            if n2 > 0:
                s = s + '1'*(n2 + 1)
    print(s)
