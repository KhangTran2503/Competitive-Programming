from sys import stdin, stdout

def solve(a,M):
    total = sum(a)
    a.sort(reverse = True)
    #print(total)
    if a[M - 1]*4*M >= total: return 'Yes'
    return 'No'



N, M = map(int,stdin.readline().rstrip().split())
a = [int(x) for x in stdin.readline().rstrip().split()]

stdout.write(solve(a,M))
