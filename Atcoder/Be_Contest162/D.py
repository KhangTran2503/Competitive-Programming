from sys import stdin,stdout


def solve(S,N):
    color = [[] for _ in range(3)]

    for i in range(N):
        if S[i] == 'R': color[0].append(i)
        elif S[i] == 'G': color[1].append(i)
        else: color[2].append(i)
    
    
    #Exclusion 
    total = len(color[0])*len(color[1])*len(color[2])

    remain = 0
    for i in range(N - 2):
        for j in range(i + 1,N - 1):
            k = j + j - i
            if k >= N: break
            
            if S[i] != S[j] and S[i] != S[k] and S[j] != S[k]:
                remain += 1
    return total - remain


    


if __name__ == "__main__": 
    #Input 
    N = int(stdin.readline().rstrip())
    S = stdin.readline().rstrip()
    stdout.write(str(solve(S,N)))
    



