n = int(input())

def check(s):
    n = len(s)
    for i in range(n//2):
        if s[i] != s[n - i -1]: return False
    return True

for _ in range(n):
    s = input()
    if (check(s)): print('YES')
    else: print('NO')