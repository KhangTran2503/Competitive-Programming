n = int(input())
x , y = map(int,input().split())

white = max(x,y)
black = max(n - x + 1,n - y + 1)
if white <= black: print('White')
else: print('Black')