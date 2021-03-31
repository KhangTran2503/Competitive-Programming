T = int(input())
for _ in range(T):
    n, k = map(int,input().split())
    a = list(map(int,input().split()))
    print(sum(a) % k)