# cook your dish here

n, k = map(int,input().split())
a = list(map(int,input().split()))

Sum = sum(a)

divisor = []
i = 1
while i*i <= Sum:
    if Sum % i == 0:
        divisor.append(i)
        divisor.append(Sum//i)
    i += 1
    
divisor = set(divisor)

ans = 0
for div in divisor:
    remain = []
    for ai in a:
        remain.append(ai % div)
    
    remain.sort()
    l = 0 
    r = len(remain) - 1;
    
    operator = 0
    while l < r:
        need = min(remain[l],div - remain[r])
        operator += need
        
        remain[l] -= need
        remain[r] += need
        
        if remain[l] == 0: l += 1
        if remain[r] == div: r -= 1
    
    if (operator <= k): ans = max(ans, div)    


print(ans)