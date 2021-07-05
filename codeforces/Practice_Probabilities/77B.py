T = int(input())

for _ in range(T):
    a, b = map(int,input().split())
    if (b == 0): print(1)
    elif (a == 0): print(0.5)
    else:
        m = 2*a*b
        t = (1/8)*a*a + a*b
        if b < a/4:
            delta = a/4 - b
            base = a*(delta/(delta + b))
            t -= (1/2)*(delta*base)
        
        ans = t/m
        print(round(ans,8))
