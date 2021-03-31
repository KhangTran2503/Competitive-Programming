
def solve(a):
    n = len(a)
    lef = 1
    rig = n - 1
    prea = [a[0]]
    preb = []
    while lef <= rig:
        
        sumb = 0
        while rig >= lef and sumb <= prea[-1]:
            sumb += a[rig]
            rig -= 1
        if sumb > 0:
            preb.append(sumb)
        if sumb <= prea[-1]:break
        
            
        suma = 0
        while lef <= rig and suma <= preb[-1]:
            suma += a[lef]
            lef += 1
        if suma > 0:
            prea.append(suma)
        if suma <= preb[-1]: break

    #print(prea,preb)

    print(len(prea) + len(preb),sum(prea),sum(preb))

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    solve(a)
