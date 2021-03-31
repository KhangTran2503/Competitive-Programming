a = int(input())
b = int(input())

S = 1
for i in range(a,a + 10):
    if i > b:
        break
    S = (S * (i % 9)) % 9

if S == 0:
    print(9)
else:
    print(S)

