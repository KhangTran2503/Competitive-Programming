from sys import stdin, stdout

N, K = map(int,stdin.readline().rstrip().split())

ans = N % K
print(min(ans,abs(ans - K)))

