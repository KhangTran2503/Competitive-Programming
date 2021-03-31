
def check(val):
    if val % 3  == 0 or val % 5 == 0: return False
    return True

N = int(input())
ans = sum(list(filter(check,range(N + 1))))
print(ans)


