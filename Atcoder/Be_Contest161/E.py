from sys import stdin, stdout

N, K, C = map(int,stdin.readline().rstrip().split())
S = stdin.readline()



vec = []
rvec = []

i = 0
while i < N:
    if S[i] == 'o':
        vec.append(i)
        i += C
    i += 1

j = N - 1
while j >= 0:
    if S[j] == 'o':
        rvec.append(j)
        j -= C
    j -= 1


ans = []
for i in range(K):
    if vec[i] == rvec[K - i - 1]:
        stdout.write(str(vec[i] + 1) + '\n')
stdout.write('\n')
