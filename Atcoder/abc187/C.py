n = int(input())

d1 = dict()
d2 = dict()
for _ in range(n):
	s = input()
	if s[0] == '!':
		d2[s[1:]] = 1
	else: d1[s] = 1

for key in d1:
	if key in d2:
		print(key)
		quit()

print('satisfiable')