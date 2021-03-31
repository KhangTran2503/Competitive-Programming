A, B = input().split()

sumA = sum([int(x) for x in A])
sumB = sum([int(x) for x in B])
print(max(sumA,sumB))