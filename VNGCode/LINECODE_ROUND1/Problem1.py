n = int(input())

d = {}

for i in range(n):
    t = input().strip()
    t = t.split(":")
    d[t[0].strip()]= t[1].strip()
    
p = input().strip()

nd = {x:d[x] for x in sorted(d.keys())}

if p in d.keys():
	cnt = 0
	for key, val in nd.items():
		if cnt > 0 or key==p:
			print(key+":", val)
			cnt += 1
		if cnt==5: break
else: print("no data")

